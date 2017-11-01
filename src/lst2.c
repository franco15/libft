/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:01:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 17:01:44 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_lst **alst, void (*del)(void *, size_t))
{
	t_lst *p;
	t_lst *t;

	p = *alst;
	while (p)
	{
		t = p;
		del(p->content, p->size);
		free(p);
		p = t->next;
	}
	*alst = NULL;
}

void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t))
{
	t_lst *p;

	p = *alst;
	del(p->content, p->size);
	free(*alst);
	*alst = NULL;
}

void	ft_lstiter(t_lst *lst, void (*f)(t_lst *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}

t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst	*new;
	t_lst	*t;
	t_lst	*r;

	if (!lst || !f)
		return (0);
	t = f(lst);
	r = ft_lstnew(t->content, t->size);
	if (r)
	{
		new = r;
		lst = lst->next;
		while (lst != NULL)
		{
			t = f(lst);
			if (!(new->next = ft_lstnew(t->content, t->size)))
				return (0);
			new = new->next;
			lst = lst->next;
		}
	}
	return (r);
}

t_lst	*ft_lstnew(void const *content, size_t size)
{
	t_lst *elem;

	if (!(elem = (t_lst*)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->size = 0;
	}
	else
	{
		elem->content = (void*)ft_memalloc(size);
		elem->content = ft_memcpy(elem->content, content, size);
		elem->size = size;
	}
	elem->next = NULL;
	return (elem);
}
