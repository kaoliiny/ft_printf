/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:23:10 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/07 18:40:30 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*joint;
	char	*s1;
	char	*s2;

	if (!str1 || !str2)
		return (NULL);
	s1 = (char *)str1;
	s2 = (char *)str2;
	joint = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joint == 0)
		return (NULL);
	ft_strcpy(joint, s1);
	ft_strcat(joint, s2);
	return (joint);
}
