/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:11:40 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 17:11:41 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (((big[i + j]) == little[j]) && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char*)s + i);
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char*)s + i);
}

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while ((big[i + j]) == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s)
{
	char	*ret;

	if (!s)
		return (0);
	while ((ft_isspace(*s) == 1))
		s++;
	if (!*s)
		return (ft_strnew(0));
	ret = (char*)(s + (ft_strlen(s) - 1));
	while (ft_isspace(*ret))
		ret--;
	return (ft_strsub(s, 0, (ret - s + 1)));
}
