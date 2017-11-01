/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:38:15 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:38:16 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_printfcolor_fd(int fd, const char *format, ...)
{
	va_list p;
	char	*tmp;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putcstr_fd(va_arg(p, char*), va_arg(p, size_t), fd);
			else if ((*(format + 1)) == 'd')
			{
				ft_putcstr_fd(tmp = ft_itoa_base(va_arg(p, int), 10),
				va_arg(p, size_t), fd);
				ft_memdel((void**)&tmp);
			}
			format += 1;
		}
		else
			write(fd, format, 1);
		format += 1;
	}
	va_end(p);
}

void			ft_printf_fd(int fd, const char *format, ...)
{
	va_list p;
	char	*str;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putstr_fd(va_arg(p, char*), fd);
			else if ((*(format + 1)) == 'd')
			{
				str = ft_itoa_base(va_arg(p, int), 10);
				ft_putstr_fd(str, fd);
				ft_memdel((void**)&str);
			}
			else if ((*(format + 1)) == 'c')
				ft_putchar_fd(va_arg(p, int), fd);
			format += 1;
		}
		else
			write(fd, format, 1);
		format += 1;
	}
	va_end(p);
}
