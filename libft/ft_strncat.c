/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:19:59 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/09 17:04:54 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int	ft_strlen(char *str)
{
	int	nbr;

	nbr = 0;
	while (str[nbr] != '\0')
		nbr++;
	return (nbr);
}

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	j;
	size_t	leght;

	j = 0;
	leght = ft_strlen(s1);
	while (j < n && s2[j] != '\0')
		s1[leght++] = s2[j++];
	j--;
	while (j < n)
	{
		s1[leght] = '\0';
		j++;
	}
	return (s1);
}
