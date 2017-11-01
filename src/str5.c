/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:11:28 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 17:11:29 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	r = i;
	while (i + 1 < size && src[j])
		dst[i++] = src[j++];
	if (r < size)
		dst[i] = '\0';
	return (r + ft_strlen(src));
}

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*ret;

	i = 0;
	l = 0;
	if (s)
	{
		while (s[l] != '\0')
			l++;
		ret = (char*)ft_memalloc(l + 1);
		if (ret)
		{
			while (i < l)
			{
				ret[i] = f(s[i]);
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (0);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		l;
	char	*ret;

	i = 0;
	l = 0;
	if (s)
	{
		while (s[l] != '\0')
			l++;
		ret = (char*)ft_memalloc(l + 1);
		if (ret)
		{
			while (i < l)
			{
				ret[i] = f(i, s[i]);
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (0);
}

char	*ft_strncatalrevez(char *s, char c, size_t n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	if (!s)
		ret = ft_strnew(n);
	else
		ret = ft_strnew(ft_strlen(s) + n);
	while (n--)
		ret[i++] = c;
	if (!s)
		return (ret);
	return (ft_strcat(ret, s));
}
