/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:56:45 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 16:56:46 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_baselen(long long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int	ft_tolower(int c)
{
	return (c >= 65 && c <= 90 ? c + 32 : c);
}

int	ft_toupper(int c)
{
	return (c >= 97 && c <= 122 ? c - 32 : c);
}
