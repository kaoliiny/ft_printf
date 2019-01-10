/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:18:38 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 21:06:07 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_strlen(char *str)
{
	int	nbr;

	nbr = 0;
	while (str[nbr] != '\0')
		nbr++;
	return (nbr);
}

char		*ft_strcat(char *s1, const char *s2)
{
	int	l;

	l = ft_strlen(s1);
	while (*s2)
		s1[l++] = *s2++;
	s1[l] = '\0';
	return (s1);
}
