/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:40:34 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:40:35 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *s)
{
	ft_printf_fd(2, "DED: %s\n", s);
	exit(EXIT_FAILURE);
}

int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s && *s != c)
			s++;
		if (!*s)
			return (i);
		s++;
	}
	return (i);
}

int		ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		else
		{
			s++;
			i++;
		}
	}
	return (i);
}

int	ft_onlyspaces(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i++] != ' ')
			j++;
	return (j);
}

int	ft_onlyzeros(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i++] != '0')
			j++;
	return (j);
}
