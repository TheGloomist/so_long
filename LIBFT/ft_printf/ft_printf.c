/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 16:28:47 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/07/14 18:09:56 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	check_conv(va_list args, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(args, int));
	else if (format == 's')
		len += print_str(va_arg(args, char *));
	else if (format == 'p')
		return (write(1, "0x", 2) + print_lhex(va_arg(args, unsigned long)));
	else if (format == 'd')
		len += print_nbr(va_arg(args, int));
	else if (format == 'i')
		len += print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += print_unsigned_dec(va_arg(args, unsigned int));
	else if (format == 'x')
		len += print_lhex(va_arg(args, unsigned int));
	else if (format == 'X')
		len += print_uphex(va_arg(args, unsigned int));
	else if (format == '%')
		return (write(1, "%", 1));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res += check_conv(args, format[i]);
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
