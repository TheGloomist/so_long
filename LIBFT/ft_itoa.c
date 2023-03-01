/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 18:57:26 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/04/30 22:14:29 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_neg(long int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int	n_length(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	rev_number(long int n, int i, char *str)
{
	char	c;

	c = (n % 10) + '0';
	n = n / 10;
	if (n > 0)
		i = rev_number(n, i, str);
	str[i] = c;
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			neg;
	int			i;
	int			len;
	long int	num;

	num = n;
	len = n_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	neg = check_neg(num);
	i = 0;
	if (neg == -1)
	{
		str[i] = '-';
		num = num * -1;
		i++;
	}
	rev_number(num, i, str);
	str[len] = '\0';
	return (str);
}
