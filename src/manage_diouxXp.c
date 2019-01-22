/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_diouxxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:01:03 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/22 23:10:47 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_base(t_format *f)
{
	if (f->fl.conv == 'd' || f->fl.conv == 'i' || f->fl.conv == 'u')
		return (10);
	if (f->fl.conv == 'o')
		return (8);
	if (ft_tolower(f->fl.conv) == 'x' || f->fl.conv == 'p')
		return (16);
	return (1);
}

static void		print_prefix(size_t number, int base,
const char space, t_format *f)
{
	f->fl.neg_value && MWID--;
	f->fl.space && !f->fl.plus && !f->fl.neg_value && MWID--;
	f->fl.plus && !f->fl.neg_value && base == 10 && MWID--;
	f->fl.hash && number && base == 8 && MWID--;
	f->fl.hash && base == 16 && (number || f->fl.conv == 'p') && (MWID -= 2);
	if (!(!f->fl.prec_dot && f->fl.zero) && !f->fl.minus)
		while (MWID-- > 0)
			manage_buff(space, f);
	f->fl.space && (f->fl.conv == 'd' || f->fl.conv == 'i') &&
	!f->fl.plus && !f->fl.neg_value && manage_buff(' ', f);
	f->fl.neg_value && manage_buff('-', f);
	f->fl.plus && !f->fl.neg_value && (f->fl.conv == 'd'
	|| f->fl.conv == 'i') && manage_buff('+', f);
	f->fl.hash && base == 8 && manage_buff('0', f);
	f->fl.hash && (number || f->fl.conv == 'p')
	&& base == 16 && manage_buff('0', f)
	&& manage_buff(f->fl.conv == 'X' ? 'X' : 'x', f);
	if (!f->fl.prec_dot && f->fl.zero && !f->fl.minus)
		while (MWID-- > 0)
			manage_buff(space, f);
}

void			handling_decimal(size_t number, t_format *f)
{
	char		*num;
	int			num_len;
	bool		is_print;
	char		space;
	const int	base = check_base(f);

	num = print_base(number, base, f);
	num_len = ft_strlen(num);
	!PREC && !number && f->fl.prec_dot && MWID++;
	PREC -= num_len + (f->fl.hash && number && base == 8);
	MWID -= (PREC > 0 ? PREC : 0) + num_len;
	space = (!f->fl.prec_dot && f->fl.zero) ? '0' : ' ';
	print_prefix(number, base, space, f);
	is_print = !(number == 0 &&
	((f->fl.prec_dot && PREC < 0) || (base == 8 && f->fl.hash)));
	while (PREC-- > 0)
		manage_buff('0', f);
	if (is_print)
		while (*num)
			manage_buff(*num++, f);
	while (MWID-- > 0)
		manage_buff(' ', f);
}
