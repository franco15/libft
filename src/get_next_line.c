/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:38:30 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:38:31 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_free(t_gnl **reminder, int fd)
{
	t_gnl			*head;

	head = reminder[fd];
	reminder[fd] = reminder[fd]->next;
	free(head);
}

static int	ft_reminder_a(t_gnl **reminder, int fd, char **line,
															t_gnl **current)
{
	if (reminder[fd])
	{
		if (ft_lst_inc(reminder[fd], '\n'))
		{
			while (reminder[fd]->data != '\n')
			{
				ft_lst_push_back(current, reminder[fd]->data);
				ft_lst_free(reminder, fd);
			}
			ft_lst_free(reminder, fd);
			*line = ft_lst_to_s(*current);
			return (1);
		}
		while (reminder[fd])
		{
			ft_lst_push_back(current, reminder[fd]->data);
			ft_lst_free(reminder, fd);
		}
	}
	return (0);
}

static int	ft_read_a(t_gnl **reminder, int fd, char **line, t_gnl **current)
{
	int				ret;
	size_t			i;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		i = 0;
		if (ft_str_inc(buf, '\n'))
		{
			while (buf[i] != '\n')
				ft_lst_push_back(current, buf[i++]);
			i++;
			*line = ft_lst_to_s(*current);
			if ((int)i < ret)
			{
				while (buf[i])
					ft_lst_push_back(&reminder[fd], buf[i++]);
			}
			return (1);
		}
		while ((int)i < ret)
			ft_lst_push_back(current, buf[i++]);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_gnl			*current;
	static t_gnl	*reminder[590432];

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	current = NULL;
	if (ft_reminder_a(reminder, fd, line, &current) == 1)
		return (1);
	reminder[fd] = NULL;
	if ((ret = ft_read_a(reminder, fd, line, &current)) == 1)
		return (1);
	*line = ft_lst_to_s(current);
	if (ft_strlen(*line) > 0)
		return (1);
	return (ret);
}
