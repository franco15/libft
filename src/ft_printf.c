/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:37:22 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/31 15:37:23 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_printfcolor(const char *format, ...)
{
	va_list p;
	char	*tmp;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putcstr(va_arg(p, char*), va_arg(p, size_t));
			else if ((*(format + 1)) == 'd')
			{
				ft_putcstr(tmp = ft_itoa_base(va_arg(p, int), 10),
				va_arg(p, size_t));
				ft_memdel((void**)&tmp);
			}
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
}

void			ft_printf(const char *format, ...)
{
	va_list p;
	char	*str;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putstr(va_arg(p, char*));
			else if ((*(format + 1)) == 'd')
			{
				str = ft_itoa_base(va_arg(p, int), 10);
				ft_putstr(str);
				ft_memdel((void**)&str);
			}
			else if ((*(format + 1)) == 'c')
				ft_putchar(va_arg(p, int));
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
}
