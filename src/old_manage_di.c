// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   old_manage_di.c                                    :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2018/12/24 20:05:12 by kaoliiny          #+#    #+#             */
// // /*   Updated: 2019/01/10 19:00:50 by kaoliiny         ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// #include "ft_printf.h"

// static int		check_base(t_format *f)
// {
// 	if (f->fl.conv == 'd' || f->fl.conv == 'i' || f->fl.conv == 'u')
// 		return(10);
// 	if (f->fl.conv == 'o')
// 		return(8);
// 	if (ft_tolower(f->fl.conv) == 'x'|| f->fl.conv == 'p')
// 		return (16);
// 	return (1);
// }

// static bool		manage_prefix(t_format *f, int base)
// {
// 	if (base == 10)
// 	{
// 		(f->fl.plus && !f-> neg_value) ? manage_buff('+', f) && f->fl.min_width-- : 0;
// 		(f->fl.space && !f->fl.plus) && manage_buff(' ', f) && f->fl.min_width--;
// 		(f->neg_value) && manage_buff('-', f) && f->fl.min_width--;
// 		return (true);
// 	}
// 	else if (f->fl.hash)
// 	{
// 		(base == 8 || base == 16) && manage_buff('0', f);
// 		(base == 16) && manage_buff((f->fl.conv == 'X') ? 'X' : 'x', f);
// 		f->fl.hash = false;
// 		return (true);
// 	}
// 	return (0);
// }

// void			handling_decimal(size_t number, t_format *f)
// {
// 	char		*num;
// 	int			prec;
// 	int			base;

// 	prec = (f->fl.precision > int_size(number)) ? f->fl.precision : int_size(number);
// 	num = print_base(number, base = check_base(f), f);
// 	(f->fl.minus || !(f->fl.min_width) || f->fl.zero) && manage_prefix(f, base);

// 	((!f->fl.minus && (f->fl.minus + f->fl.space + f->fl.plus)) || base != 10)
// 	&& f->fl.min_width-- && f->fl.precision && f->fl.precision++ && f->fl.min_width--;
	
// 	while ((--f->fl.min_width - prec + 1) > 0 && !f->fl.minus)
// 		(f->fl.zero && !f->fl.precision) ? manage_buff('0', f) : manage_buff(' ', f);
// 	(!f->fl.minus) ? manage_prefix(f, base) : 0;

// 	//(number < 0) ? manage_buff('-', f) && (number *= -1) : 0;
// 	while (*num && number)
// 		(f->fl.precision-- > int_size(number)) ? manage_buff('0', f) : manage_buff(*num++, f);
// 	while ((f->fl.min_width-- - prec + 1) > 0 && f->fl.minus)
// 		(f->fl.zero) ? manage_buff('0', f) : manage_buff(' ', f);
// }
