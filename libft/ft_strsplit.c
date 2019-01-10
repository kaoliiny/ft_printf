/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:57:59 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/10 18:43:41 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	size = start;
	new_s = (char *)malloc(sizeof(char) * (unsigned int)len + 1);
	if (new_s == 0)
		return (NULL);
	while (start < len + size && s[i])
		new_s[i++] = s[start++];
	new_s[i] = '\0';
	return (new_s);
}

static int	count_words(char const *s, char c)
{
	int				word;
	unsigned int	b;

	b = 0;
	word = 0;
	while (s[b])
	{
		while (s[b] == c && s[b])
			b++;
		if (s[b] == '\0')
			break ;
		while (s[b] != c && s[b] != '\0')
			b++;
		word++;
	}
	return (word);
}

static void	costylos(char const *s, char **s_new, int count, char c)
{
	int	b;
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (count--)
	{
		b = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			b++;
		}
		s_new[word] = ft_strsub(s, i - b, b);
		s_new[word][b] = '\0';
		word++;
	}
	s_new[word] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**s_new;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!(s_new = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	costylos(s, s_new, count, c);
	return (s_new);
}
