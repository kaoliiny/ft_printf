/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 02:06:00 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/22 23:10:49 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_size(size_t n)
{
	size_t	size;

	size = (n == 0) ? 0 : 1;
	while ((n /= 10) > 0)
		size++;
	return (size);
}

int		ft_isupper_alpha(int a)
{
	if ((a >= 65 && a <= 90))
		return (1);
	else
		return (0);
}

char	*swap(int j, char source[])
{
	int		i;
	char	*x;
	char	*tmp;

	i = 0;
	x = (char *)malloc(sizeof(char) * (j + 1));
	tmp = x;
	while (j >= 0)
		x[i++] = source[j--];
	x[i] = '\0';
	free(tmp);
	return (x);
}

char	*print_base(size_t num, const int base, t_format *f)
{
	int		i;
	size_t	mod;
	char	x[70];
	int		temp;

	i = 0;
	while (num >= (size_t)base)
	{
		mod = num;
		if ((temp = mod % (size_t)base) <= 9)
			x[i] = temp + '0';
		else
			x[i] = temp + ((base == 16 && f->fl.conv == 'X') ? 55 : 87);
		num /= base;
		i++;
	}
	if (num >= 10)
		x[i] = num + ((base == 16 && f->fl.conv == 'X') ? 55 : 87);
	else
		x[i] = num + '0';
	return (swap(i, x));
}
