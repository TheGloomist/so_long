/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 15:51:37 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/04/30 22:17:28 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_i;
	size_t	n_i;

	if (!needle[0])
		return ((char *)haystack);
	h_i = 0;
	while (haystack[h_i])
	{
		n_i = 0;
		while (haystack[h_i + n_i] == needle[n_i] && h_i + n_i < len)
		{
			if (!haystack[h_i + n_i] && !needle[n_i])
				return ((char *)haystack + h_i);
			n_i++;
		}
		if (!needle[n_i])
			return ((char *)haystack + h_i);
		h_i++;
	}
	return (NULL);
}
