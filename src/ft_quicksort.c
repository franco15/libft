/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:50:01 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 16:50:02 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void **s, int i, int j)
{
	void	*s3;

	s3 = s[i];
	s[i] = s[j];
	s[j] = s3;
}

void	ft_quicksort(void **s, int start, int end,
		int (comp)(void *, void *))
{
	int		i;
	int		j;
	void	*pivot;

	if (start >= end)
		return ;
	i = start;
	j = end;
	pivot = s[(start + end) / 2];
	while (i <= j)
	{
		while (comp(s[i], pivot) < 0)
			i++;
		while (comp(s[j], pivot) > 0)
			j--;
		if (i <= j)
			ft_swap(s, i++, j--);
	}
	ft_quicksort(s, start, j, comp);
	ft_quicksort(s, i, end, comp);
}
