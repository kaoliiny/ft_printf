/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:55:09 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/24 00:26:09 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_check_fd(t_list **lst, const int fd)
{
	t_list	*ls;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(NULL, fd);
		(*lst)->content_size = fd;
		return (*lst);
	}
	ls = *lst;
	while (ls != NULL)
	{
		if ((const int)ls->content_size == fd)
			return (ls);
		if (ls->next == NULL)
		{
			ls->next = ft_lstnew(NULL, fd);
			ls->next->content_size = fd;
			return (ls->next);
		}
		ls = ls->next;
	}
	return (NULL);
}

void			ft_joint(char **line, char *buf)
{
	char		*tmp;

	if (!buf)
		return ;
	if (!*line)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
}

int				list_check(char **line, t_list *list)
{
	char *p;
	char *tmp;

	p = NULL;
	if (list->content && (p = ft_strchr(list->content, '\n')))
	{
		*p = '\0';
		ft_joint(line, list->content);
		tmp = list->content;
		list->content = p[1] ? ft_strdup(p + 1) : NULL;
		free(tmp);
		return (1);
	}
	else if (list->content)
	{
		ft_joint(line, list->content);
		ft_strdel((char**)&list->content);
	}
	return (0);
}

static int		ft_read(char **line, t_list *list)
{
	ssize_t		read_d;
	char *const	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	char		*p;
	char		*tmp;

	p = NULL;
	while (buf && (read_d = read(list->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[read_d] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			ft_joint(line, buf);
			tmp = list->content;
			list->content = p[1] ? ft_strdup(p + 1) : NULL;
			free(tmp);
			break ;
		}
		else
			ft_joint(line, buf);
	}
	free(buf);
	if (read_d == -1)
		return (-1);
	return ((line && *line) || (list->content && *((char*)list->content)));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*list_fd;
	int				ret;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	list_fd = ft_check_fd(&list, fd);
	if ((ret = list_check(line, list_fd)) != 1)
		ret = ft_read(line, list_fd);
	return (ret);
}
