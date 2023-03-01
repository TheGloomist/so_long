/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/13 14:15:58 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/09/06 17:05:40 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	if (!str)
		return (ret);
	while (str[ret] != '\0')
		ret++;
	return (ret);
}
