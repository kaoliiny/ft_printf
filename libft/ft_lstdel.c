/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:37:06 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 18:41:32 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	if (!alst || !(del) || !*del)
		return ;
	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
