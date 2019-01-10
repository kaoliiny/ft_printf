/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:56:41 by exam              #+#    #+#             */
/*   Updated: 2018/11/10 18:45:58 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

void		ft_capitalizer(char *str)
{
	int i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i++;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' '
					|| str[i - 1] == '\n' || str[i - 1] == '\t')))
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != ' '
					&& str[i - 1] != '\t' && str[i - 1] != '\n')
			str[i] += 32;
		i++;
	}
	ft_putstr(str);
}
