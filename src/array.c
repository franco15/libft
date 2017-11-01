/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:36:10 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:36:13 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(void **arr, int len)
{
	int		i;
	void	**tmp;

	i = 0;
	tmp = arr;
	if (!arr)
		return ;
	while (i < len)
	{
		free(tmp[i]);
		tmp[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}

size_t	ft_arrlen(void **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_arrdup(char **s, int len)
{
	int		i;
	char	**ret;

	i = 0;
	ret = (char**)ft_memalloc(sizeof(char*) * len);
	while (i < len)
	{
		ret[i] = ft_strdup(s[i]);
		i++;
	}
	return (ret);
}
