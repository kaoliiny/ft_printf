/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:00:55 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 18:13:04 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	sum;
	int					minus;

	i = 0;
	sum = 0;
	minus = 1;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i++] - '0';
		if (sum >= 9223372036854775807 && minus == 1)
			return (-1);
		if (sum > 9223372036854775807 && minus == -1)
			return (0);
	}
	return ((int)sum * minus);
}
