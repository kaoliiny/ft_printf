/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:05:12 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/17 00:34:02 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_f(ssize_t integer, char *floating,
ssize_t int_p, t_format *f)
{
	char *x;

    (integer < 0) && 	manage_buff('-', f);
	x = ft_itoa((size_t)ABS(integer));
    f->fl.space && !f->fl.plus && (int_p > 0) && manage_buff(' ', f);
	f->fl.plus && (int_p > 0) && manage_buff('+', f);
	while (*x)
		manage_buff(*x++, f);
	(*floating) && manage_buff('.', f);
	while (*floating)
		manage_buff(*floating++, f);
}

void	handling_f(t_format *f)
{
	int			i;
	char		*x;
	ssize_t		int_p;
	long double fl;
	long double fl_p;

	i = -1;
	fl = (f->fl.lll) ? va_arg(f->ap, long double) : va_arg(f->ap, double);
	int_p = fl;
	fl_p = ABS(fl - int_p);
	(!PREC) && (!f->fl.prec_dot) && (PREC = 6);
	x = (char *)malloc(sizeof(char) * PREC);
	while (++i < PREC)
	{
		x[i] = fl_p * 10 + '0';
		fl_p = (fl_p * 10) - (x[i] - '0');
	}
	if (fl_p * 10 + '0' >= '5')
	{
		while (x[--i] == '9')
			x[i] = '0';
		x[i] += 1;
	}
	while (!f->fl.minus && f->fl.prec_dot && --MWID - (int_p < 0) ? 1 : 0 > PREC + int_size(ABS(int_p)))
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	print_f(int_p, x, int_p, f);
	while (f->fl.minus && --MWID - (int_p < 0) ? 1 : 0 > PREC + int_size(ABS(int_p)))
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
}
