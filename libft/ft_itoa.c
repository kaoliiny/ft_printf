/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:14:07 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/16 01:15:56 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_size(size_t n)
{
	int	size;

	size = 1;
	while ((n /= 10) > 0)
		size++;
	return (size);
}

char			*ft_itoa(size_t n)
{
	int		size;
	char	*str;

	size = count_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size-- > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
