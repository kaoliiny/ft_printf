/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:43:04 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/09 14:36:57 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		eol;
	char	*new;
	size_t	len;

	i = 0;
	eol = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	while ((s[i] <= 32 || s[i] == ',') && s[i] != '\0')
		i++;
	while ((s[len - eol] <= 32 || s[len - eol] == ',') && s[i] != '\0')
		eol++;
	if (!(new = ft_strsub(s, i, len - i - eol + 1)))
		return (NULL);
	return (new);
}
