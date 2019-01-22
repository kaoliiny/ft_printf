/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:36:40 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/21 17:54:22 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdbool.h"
# include "libft.h"

# define BUFF_SIZE 4096
# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))
# define PREC	f->fl.precision
# define MWID	f->fl.min_width

typedef unsigned	uint;

typedef struct	s_flags
{
	bool		zero;
	bool		hash;
	bool		space;
	bool		plus;
	bool		minus;
	bool		l;
	bool		h;
	bool		j;
	bool		z;
	bool		lll;
	bool		ll;
	bool		hh;

	char		conv;
	int			min_width;
	int			precision;
	bool		prec_dot;
	bool		neg_value;

}				flags;

typedef struct	s_format
{
	flags		fl;
	va_list		ap;
	int			sum;
	char		*buff;

}				t_format;

int				ft_printf(const char *format, ...);

bool			handling_c(t_format *f);
bool			handling_s(t_format *f);
void			handling_f(t_format *f);
bool			handling_char(int chr, t_format *f);

void			handling_decimal(size_t num, t_format *f);
bool			check_conv(const char *str, t_format *f);
char			*print_base(size_t num, const int base, t_format *f);
bool			manage_buff(int c, t_format *f);

int				ft_isupper_alpha(int a);
int				int_size(size_t n);

#endif