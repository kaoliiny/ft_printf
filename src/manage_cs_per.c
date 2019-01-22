/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cs_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 02:05:22 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/22 23:10:43 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_stracii(char *tmp)
{
	while (*tmp)
		if (!ft_isascii(*tmp++))
			return (0);
	return (1);
}

bool	handling_c(t_format *f)
{
	while (--f->fl.min_width > 0 && !f->fl.minus)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	manage_buff(va_arg(f->ap, int), f);
	while (f->fl.min_width-- > 0 && f->fl.minus)
		manage_buff(' ', f);
	return (0);
}

bool	handling_s(t_format *f)
{
	int			precision;
	char		*tmp;
	int			i;
	const char	*str = "(null)";

	i = -1;
	if (!(tmp = va_arg(f->ap, char *)))
		tmp = (char*)str;
	precision = (!f->fl.prec_dot || ((int)ft_strlen(tmp) < PREC))
	? ft_strlen(tmp) : PREC;
	if (!is_stracii(tmp))
		return (1);
	while (!f->fl.minus && f->fl.min_width-- - precision > 0)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	(PREC == 0) ? PREC = -1 : 0;
	while (tmp[++i] && (PREC-- > 0 || !f->fl.prec_dot))
		manage_buff(tmp[i], f);
	while ((f->fl.min_width-- - (i)) > 0 && f->fl.minus)
		manage_buff(' ', f);
	return (0);
}

bool	handling_char(int chr, t_format *f)
{
	if (chr == 1)
	{
		PREC = va_arg(f->ap, long long int);
		(PREC < 0) && (f->fl.prec_dot = false)
		&& (PREC = 0);
	}
	else if (chr == 0)
	{
		f->fl.min_width = va_arg(f->ap, long long int);
		(f->fl.min_width < 0) && (f->fl.minus = true)
		&& (f->fl.min_width *= -1);
	}
	else
	{
		while (--f->fl.min_width > 0 && !f->fl.minus)
			(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
		manage_buff(chr, f);
		while (f->fl.min_width-- > 0 && f->fl.minus)
			manage_buff(' ', f);
	}
	return (1);
}
