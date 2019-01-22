/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:04:57 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/21 22:58:26 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

bool	print_buff(t_format *f)
{
	write(1, f->buff, f->sum);
	return (1);
}

bool	manage_buff(int c, t_format *f)
{
	f->buff[f->sum++] = c;
	if (!f->sum % BUFF_SIZE)
	{
		ft_bzero(&f->buff, 4096);
		print_buff(f);
	}
	return (true);
}

bool	manage_flags(const char **str, t_format *f)
{
	return ((**str == '0' && (f->fl.zero = true))
	|| (**str == '+' && (f->fl.plus = true))
	|| (**str == '-' && (f->fl.minus = true))
	|| (**str == ' ' && (f->fl.space = true))
	|| (**str == '#' && (f->fl.hash = true))
	|| (**str == 'j' && (f->fl.j = true))
	|| (**str == 'z' && (f->fl.z = true))
	|| (**str == 'L' && (f->fl.lll = true))
	|| ((**str == 'l') && (*str)[1] == 'l' && (f->fl.ll = true) && ++(*str))
	|| (**str == 'l' && (f->fl.l = true))
	|| (**str == 'h' && (*str)[1] == 'h' && (f->fl.hh = true) && ++(*str))
	|| (**str == 'h' && (f->fl.h = true))
	|| (**str == '*' && handling_char(0, f)));
}

bool	manage_field(const char *str, t_format *f)
{
	while (*str)
		if (*str == '%' && *(++str))
		{
			while (*str)
				if (manage_flags(&str, f))
					str++;
				else if (ft_atoi(str))
					str +=
					int_size((f->fl.min_width = ft_atoi(str)));
				else if (*str == '.' && (f->fl.prec_dot = true) && ++str)
					(((*str == '*') && handling_char(1, f)) && ++str) ||
					(str +=
					int_size((*str == '0') ? 1 : (PREC = ft_atoi(str))));
				else
				{
					if (check_conv(str++, f))
						return (1);
					ft_bzero(&f->fl, sizeof(flags));
					break ;
				}
		}
		else
			*str != '\0' && manage_buff(*str++, f);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	static t_format		f;

	f.sum = 0;
	if (!f.buff)
		f.buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	va_start(f.ap, format);
	(manage_field(format, &f)) ? (print_buff(&f))
	&& (f.sum = -1) : print_buff(&f);
	va_end(f.ap);
	return (f.sum);
}
