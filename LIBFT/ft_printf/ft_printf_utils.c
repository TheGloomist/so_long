/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 21:56:20 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/07/16 12:03:36 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_str(char *str)
{
	size_t	str_len;

	if (!str)
		return (write(1, "(null)", 6));
	str_len = ft_strlen(str);
	return (write(1, str, str_len));
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}
