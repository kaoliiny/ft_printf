/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:39:47 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 21:15:41 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **x)
{
	unsigned char **ap;

	ap = (unsigned char **)x;
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}