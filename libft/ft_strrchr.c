/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:53:49 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/01 20:19:02 by kaoliiny         ###   ########.fr       */
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

char		*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str + ft_strlen((char *)str);
	while (*s != c)
	{
		if (s == (char *)str)
			return (NULL);
		s--;
	}
	return (s);
}
