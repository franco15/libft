/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:47:35 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 16:47:36 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termcmd(char *s)
{
	if (!s)
		return ;
	ft_putstr_fd(tgetstr(s, NULL), 2);
}

void	ft_clearscreen(int rows)
{
	while (--rows >= 0)
	{
		ft_cursor_goto(0, rows);
		ft_termcmd("dl");
	}
}

void	ft_cursor_goto(int x, int y)
{
	char *str1;
	char *str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, 2);
	}
}

size_t	ft_max_len(char **s)
{
	int		i;
	int		t;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((t = ft_strlen(s[i++])) > len)
			len = t;
	}
	return (len);
}
