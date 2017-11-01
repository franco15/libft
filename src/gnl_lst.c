/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:38:36 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:38:38 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_inc(t_gnl *lst, char c)
{
	t_gnl		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

size_t	ft_lst_len(t_gnl *lst)
{
	size_t	i;
	t_gnl	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_gnl	*ft_lst_new(char data)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lst_push_back(t_gnl **begin_lst, char data)
{
	t_gnl	*lst;

	if (*begin_lst == NULL)
	{
		*begin_lst = ft_lst_new(data);
		return ;
	}
	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	lst->next = ft_lst_new(data);
}

char	*ft_lst_to_s(t_gnl *lst)
{
	char		*str;
	size_t		i;
	t_gnl		*tmp;
	t_gnl		*head;

	tmp = lst;
	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * ft_lst_len(tmp) + 1)))
		return (NULL);
	while (tmp)
	{
		str[i++] = tmp->data;
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	str[i] = '\0';
	return (str);
}
