/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:08:09 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/10 23:28:36 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
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

static	void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;
	size_t	size;

	i = 0;
	size = start;
	if ((!s) || (int)len < 0)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * ((unsigned int)len + 1));
	if (new_s == 0 || *new_s == 1)
		return (NULL);
	ft_bzero(new_s, len + 1);
	while (start < len + (size_t)size && s[i])
		new_s[i++] = s[start++];
	return (new_s);
}
