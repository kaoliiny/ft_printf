/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:04:57 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/12 12:29:09 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void print_buff(t_format *f)
{
	ft_putstr(f->buff);
}

bool	manage_buff(int c, t_format *f)
{
	(c != 0) ? f->buff[f->sum++] = c : 0;
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
	|| (**str == 'l' &&	(*str)[1] == 'l' && (f->fl.ll = true) && ++(*str))
	|| (**str == 'l' && (f->fl.l = true))
	|| (**str == 'h' &&	(*str)[1] == 'h' && (f->fl.hh = true) && ++(*str))
	|| (**str == 'h' && (f->fl.h = true)));
}

void	manage_field(const char *str, va_list ap, t_format *f)
{
	int tmp;

	while (*str)
		if (*str == '%' && *(++str))
		{
			while (*str)
				if (manage_flags(&str, f))
					str++;
				else if ((tmp = ft_atoi(str)))
					str +=
					int_size((f->fl.min_width = tmp));
				else if (*str == '.' && (f->fl.prec_dot = true) && ++str )
					str +=
					int_size(f->fl.precision = ft_atoi(str));
				else
				{
					check_conv(str++, f);
					ft_bzero(&f->fl, sizeof(flags));
					break ;
				}
		}
		else
			manage_buff(*str++, f);
}

int		ft_printf(const char *format, ...)
{
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	f.buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	va_start(f.ap, format);
	manage_field(format, f.ap, &f);
	va_end(f.ap);
	print_buff(&f);
	// if (*f.buff)
	// 	free(f.buff);
	return (f.sum);
}
