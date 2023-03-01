/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 18:55:32 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/07/11 11:13:32 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;

	s = size * count;
	if ((s < count || s < size) && s != 0)
		return (NULL);
	dst = malloc(s);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, s);
	return (dst);
}
