/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 19:03:53 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/04/30 22:16:37 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_i;
	size_t	dst_i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	src_i = 0;
	dst_i = dst_len;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (src[src_i] && dst_i + 1 < dstsize)
	{
		dst[dst_i] = src[src_i];
		src_i++;
		dst_i++;
	}
	dst[dst_i] = '\0';
	return (dst_len + src_len);
}
