/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:10:44 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/12 19:00:19 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char))
{
	int		i;
	int		size;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
