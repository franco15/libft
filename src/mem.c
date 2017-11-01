/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:39:00 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:39:01 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = 0;
	p = malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len-- > 0)
		*s++ = c;
	return (b);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p;
	const char	*s;

	i = 0;
	s = src;
	p = dst;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}
