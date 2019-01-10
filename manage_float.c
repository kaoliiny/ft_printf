/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:05:12 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/10 17:08:34 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_f(size_t integer, char	*floating, t_format *f)
{
	char *x;

	x = ft_itoa(integer);
	while (*x)
		manage_buff(*x++, f);
	manage_buff('.', f);
	while (*floating)
		manage_buff(*floating++, f);
}

void handling_f(t_format *f)
{
	char	*x;
	long double fl;
	long double fl_p;
	size_t int_p;
	int i;

	i = -1;
	
	if (f->fl.lll)
	{
		fl = va_arg(f->ap, long double);
		int_p = fl;
		fl_p = fl - int_p;
		x = (char *)malloc(sizeof(char) * f->fl.precision);
		while(++i < f->fl.precision)
		{
			x[i] = (fl_p * 10) + '0';
			fl_p = (fl_p * 10) - (x[i] - '0');
		}
	}
	else
	{
		fl = va_arg(f->ap, double);
		int_p = fl;
		fl_p = fl - int_p;
		(!f->fl.precision) && (f->fl.precision = 6);
		x = (char *)malloc(sizeof(char) * f->fl.precision);
		while(++i < f->fl.precision)
		{
			x[i] = (fl_p * 10) + '0';
			fl_p = (fl_p * 10) - (x[i] - '0');
		}
	}
	while (!f->fl.minus && --f->fl.min_width > (f->fl.precision + int_size(int_p)))
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	print_f(int_p, x, f);
	while (f->fl.minus && --f->fl.min_width > (f->fl.precision + int_size(int_p)))
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
}