/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:45:56 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 16:45:57 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 11 || c == 13 || c == 10 || c == '\f');
}

int		ft_isallupper(char *s)
{
	while (*s)
	{
		if (*s < 'A' || *s > 'Z')
			return (0);
		s++;
	}
	return (1);
}

int	ft_isletter(char uk, char k)
{
	if (uk == k || uk == (k - 32) || uk == (k + 32))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9'));
}
