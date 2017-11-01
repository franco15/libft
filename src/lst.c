/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:38:45 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:38:48 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*ft_lstpush(t_lst *list, void *content)
{
	t_lst	*tmp;

	if (!content)
		return (NULL);
	if (!list)
	{
		list = (t_lst *)ft_memalloc(sizeof(t_lst));
		list->content = content;
		list->next = NULL;
	}
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_lst *)ft_memalloc(sizeof(t_lst));
		tmp->next->content = content;
		tmp->next->next = NULL;
	}
	return (list);
}

void		ft_lstforeach(t_lst *list, void (*f)())
{
	t_lst		*tmp;

	tmp = list;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

void		ft_lst_rec_free(t_lst *list)
{
	if (list)
	{
		ft_lst_rec_free(list->next);
		free(list);
	}
}

void	ft_lstadd(t_lst **alst, t_lst *n)
{
	t_lst	*p;

	p = n;
	p->next = *alst;
	*alst = p;
}

void	ft_lstaddback(t_lst **alst, t_lst *n)
{
	t_lst	*tmp;

	if (!*alst && !n)
		return ;
	if (!*alst)
		*alst = n;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n;
	}
}
