/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:56:23 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/10 18:28:22 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_randint(void)
{
	int i;
	int randint;

	i = 420;
	randint = (int)&i % 1000;
	if (randint < 0)
		randint *= (-1);
	return (randint);
}
