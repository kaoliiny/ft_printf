/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:42:08 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/01 20:21:09 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int symbol)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (str[0] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] == symbol)
				return (&str[i]);
			i++;
		}
	}
	if (symbol == '\0')
		str = &str[i];
	else if (str[i] == '\0')
		return (0);
	return (str);
}
