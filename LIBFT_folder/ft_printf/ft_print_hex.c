/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 15:58:31 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/07/11 16:32:25 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lhex(unsigned long n)
{
	char	*hex_str_low;

	hex_str_low = "0123456789abcdef";
	if (n > 15)
		return (print_lhex(n / 16) + print_lhex(n % 16));
	return (write(1, &hex_str_low[n], 1));
}

int	print_uphex(unsigned int n)
{
	char	*hex_str_up;

	hex_str_up = "0123456789ABCDEF";
	if (n > 15)
		return (print_uphex(n / 16) + print_uphex(n % 16));
	return (write(1, &hex_str_up[n], 1));
}
