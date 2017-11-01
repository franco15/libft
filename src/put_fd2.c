/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:08:05 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 17:08:06 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		set_color_fd(int c, int fd)
{
	ft_putstr_fd("\033[", fd);
	ft_putnbr_fd(c, fd);
	ft_putchar_fd('m', fd);
}

void		ft_putcstr_fd(char const *s, size_t col, int fd)
{
	set_color_fd(col, fd);
	ft_putstr_fd(s, fd);
	set_color_fd(0, fd);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
