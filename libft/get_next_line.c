/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:06:06 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:23:38 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rest				*newrest(const int fd)
{
	t_rest			*new;

	if ((new = (t_rest*)malloc(sizeof(t_rest))) == NULL)
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char				*check_rest(char **pre_str, char *rest)
{
	char			*r_str;

	if ((*pre_str = ft_strchr(rest, '\n')) != NULL)
	{
		**pre_str = '\0';
		r_str = ft_strdup(rest);
		ft_strcpy(rest, ++(*pre_str));
	}
	else
	{
		r_str = ft_strdup(rest);
		ft_strclr(rest);
	}
	return (r_str);
}

int					gnl(int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	int				b_read;
	char			*pre_str;
	char			*tmp;

	b_read = 1;
	pre_str = NULL;
	*line = check_rest(&pre_str, rest);
	while (pre_str == NULL && (b_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[b_read] = '\0';
		if ((pre_str = ft_strchr(buf, '\n')) != NULL)
		{
			*pre_str = '\0';
			ft_strcpy(rest, ++pre_str);
			ft_strclr(--pre_str);
		}
		tmp = *line;
		if ((*line = ft_strjoin(tmp, buf)) == NULL || b_read < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (b_read != 0 || ft_strlen(*line) != 0
		|| ft_strlen(rest) != 0) ? 1 : 0;
}

int					get_next_line(int fd, char **line)
{
	static t_rest	*list;
	t_rest			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (list == NULL)
		list = newrest(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newrest(fd);
		tmp = tmp->next;
	}
	return (gnl(fd, line, tmp->rest));
}
