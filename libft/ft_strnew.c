/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:37:19 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/13 14:03:41 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;

	i = 0;
	b1 = (unsigned char *)b;
	while (i < len)
	{
		b1[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char			*ft_strnew(size_t size)
{
	char *x;

	if (!(x = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	return (ft_memset(x, '\0', size + 1));
}
