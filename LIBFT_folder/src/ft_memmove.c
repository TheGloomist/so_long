/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 18:59:37 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/07/11 11:36:04 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*store_src;
	char	*store_dst;

	i = 0;
	store_src = (char *)src;
	store_dst = (char *)dst;
	if (store_src < store_dst)
	{
		while (len)
		{
			len--;
			store_dst[len] = store_src[len];
		}
	}
	else
		ft_memcpy (store_dst, store_src, len);
	return (dst);
}
