/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:52:28 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 16:52:28 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitnuml(unsigned long long int n, int base)
{
	int						i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char		*ft_itoa_basel(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789abcdef");
	if (value == 0 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_digitnuml(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}
