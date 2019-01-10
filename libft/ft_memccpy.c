/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:37:47 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/08 21:09:28 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				check;

	d = dst;
	s = (unsigned char *)src;
	check = 0;
	while (check < (int)n)
	{
		d[check] = s[check];
		if (d[check] == (unsigned char)c)
			return (dst + check + 1);
		check++;
	}
	return (NULL);
}
