/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:05:12 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/10 17:13:13 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		get_signed(t_format *f)
{
	ssize_t	res;

	(f->fl.j && (res = va_arg(f->ap, intmax_t)))
	|| (f->fl.z && (res = va_arg(f->ap, ssize_t)))
	|| (f->fl.l && (res = va_arg(f->ap, long)))
	|| (f->fl.ll && (res = va_arg(f->ap, long long)))
	|| (f->fl.h && (res = (short)va_arg(f->ap, int)))
	|| (f->fl.hh && (res = (char)va_arg(f->ap, int)))
	|| (res = va_arg(f->ap, int));
	(res < 0) && (f->neg_value = true);
	return ((res < 0) ? -res : res);
}

static size_t		get_unsigned(t_format *f)
{
	size_t	res;

	(f->fl.j && (res = va_arg(f->ap, uintmax_t)))
	|| (f->fl.z && (res = va_arg(f->ap, size_t)))
	|| (f->fl.l && (res = va_arg(f->ap, unsigned long)))
	|| (f->fl.ll && (res = va_arg(f->ap, unsigned long long)))
	|| (f->fl.h && (res = (unsigned short)va_arg(f->ap, uint)))
	|| (f->fl.hh && (res = (unsigned char)va_arg(f->ap, uint)))
	|| (res = va_arg(f->ap, uint));
	return (res);
}

void		check_conv(const char *str, t_format *f)
{
	ft_isupper_alpha(*str) && (f->fl.l = true);
	f->fl.conv = (*str == 'X') ? 'X' : ft_tolower(*str);
	(f->fl.conv == 'p') && (f->fl.hash = true)
	&& (f->fl.z = true);
	if (f->fl.conv == 'd' || f->fl.conv == 'i')
		handling_decimal(get_signed(f), f);
	else if (f->fl.conv == 'o' || f->fl.conv == 'u'
	|| ft_tolower(f->fl.conv) == 'x' || f->fl.conv == 'p')
		handling_decimal(get_unsigned(f), f);
	else if (f->fl.conv == 'c')
		handling_c(f);
	else if (f->fl.conv == 's')
		handling_s(f);
	else if (f->fl.conv == 'f')
		handling_f(f);
	else if (*str == '%')
		manage_buff(*str, f);
}