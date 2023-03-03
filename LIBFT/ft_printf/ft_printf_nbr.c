/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_nbr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 21:56:17 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/09/15 15:58:08 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(long int num)
{
	char	c;
	int		neg;

	neg = 0;
	if (num < 0)
	{
		num = num * -1;
		neg = print_char('-');
	}
	if (num >= 10)
		return (print_nbr(num / 10) + print_nbr(num % 10) + neg);
	c = num + '0';
	return (write(1, &c, 1) + neg);
}

int	print_unsigned_dec(unsigned int num)
{
	char	c;

	if (num >= 10)
		return (print_unsigned_dec(num / 10) + print_unsigned_dec(num % 10));
	c = num + '0';
	return (write(1, &c, 1));
}
