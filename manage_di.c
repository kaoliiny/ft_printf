#include "ft_printf.h"
#define PREC	f->fl.precision
#define MWID	f->fl.min_width

static int		check_base(t_format *f)
{
	if (f->fl.conv == 'd' || f->fl.conv == 'i' || f->fl.conv == 'u')
		return(10);
	if (f->fl.conv == 'o')
		return(8);
	if (ft_tolower(f->fl.conv) == 'x'|| f->fl.conv == 'p')
		return (16);
	return (1);
}

static void		print_prefix(size_t number, int base
, const char width_chr, t_format *f)
{
	f->neg_value && MWID--;
	f->fl.plus && !f->neg_value && (base == 10) && MWID--;
	f->fl.hash && number && (base == 8 || base == 16) && MWID--;
	f->fl.hash && number && (base == 16) && MWID--;
	if (!f->fl.zero && !f->fl.minus)
		while (MWID-- > 0)
			manage_buff(width_chr, f);
	f->fl.space && manage_buff(' ', f);
	f->neg_value && manage_buff('-', f);
	f->fl.plus && !f->neg_value && base == 10 && manage_buff('+', f);
	f->fl.hash && number && (base == 8 || base == 16) && manage_buff('0', f);
	f->fl.hash && number && (base == 16)
	&& manage_buff(f->fl.conv == 'X' ? 'X' : 'x', f);
	if (f->fl.zero && !f->fl.minus)
		while (MWID-- > 0)
			manage_buff(width_chr, f);
}

void			handling_decimal(size_t number, t_format *f)
{
	char		*num;
	int			num_len;
	const char	width_chr = f->fl.zero ? '0' : ' ';
	const char	prec_chr = f->fl.zero ? ' ' : '0';
	const int	base = check_base(f);

	num = print_base(number, base, f);
	num_len = ft_strlen(num);
	PREC -= num_len + (f->fl.hash && number && (base == 8));
	MWID -= (PREC > 0 ? PREC : 0) + num_len;

	print_prefix(number, base, width_chr, f);
	while (PREC-- > 0)
		manage_buff(prec_chr, f);
	// if (PREC != num_len - 1)
		while (*num)
			manage_buff(*num++, f);
	while (MWID-- > 0)
		manage_buff(width_chr, f);
}
