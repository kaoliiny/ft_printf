/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 00:58:03 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/12 19:20:52 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *src)
{
	char	*src_new;
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (src[nbr] != '\0')
		nbr += 1;
	src_new = (char *)malloc(sizeof(char) * (nbr + 1));
	if (src_new == 0)
		return (NULL);
	while (i <= nbr)
	{
		src_new[i] = src[i];
		i++;
	}
	src_new[i] = '\0';
	return (src_new);
}
