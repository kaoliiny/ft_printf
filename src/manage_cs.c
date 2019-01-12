/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 02:05:22 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/12 11:53:25 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handling_c(t_format *f)
{
	while (--f->fl.min_width > 0 && !f->fl.minus)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	manage_buff(va_arg(f->ap, int), f);
	while (f->fl.min_width-- > 0 && f->fl.minus)
		manage_buff(' ', f);
}

void	handling_s(t_format *f)
{
	char		*tmp;
	int			a;
	int			i;
	const char	*str = "(null)";

	i = -1;
	if (!(tmp = va_arg(f->ap, char *)))
	{
		while (*str)
			manage_buff(*str++, f);
		return ;
	}
	a = ft_strlen(tmp) - 1;
	while ((--(f->fl.min_width) - a) > 0 && !f->fl.minus)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	(f->fl.precision == 0) ? f->fl.precision = -1 : 0;
	while (tmp[++i] && (f->fl.precision)--)
		manage_buff(tmp[i], f);
	while (((f->fl.min_width)-- - (i - 1)) > 0 && f->fl.minus)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
}

void	handling_percent(t_format *f)
{
	while (--f->fl.min_width > 0 && !f->fl.minus)
		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
	manage_buff('%', f);
	while (f->fl.min_width-- > 0 && f->fl.minus)
		manage_buff(' ', f);
}