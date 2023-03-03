/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/13 14:15:50 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/03/03 18:28:55 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i + 1);
	else
		return (-1);
}

char	*allocate_line(char *old_line, const char *new_part, int nl)
{
	size_t	len;
	char	*expanded_line;

	if (nl == -1)
		len = protected_strlen(old_line) + protected_strlen(new_part);
	else
		len = protected_strlen(old_line) + nl;
	if (len == 0)
		return (NULL);
	expanded_line = (char *) malloc(sizeof(char) * (len + 1));
	if (expanded_line == NULL)
		return (NULL);
	return (expanded_line);
}

char	*add_to_line(char *old_line, const char *new_part, int nl)
{
	char	*expanded_line;
	int		i1;
	int		i2;

	expanded_line = allocate_line(old_line, new_part, nl);
	if (expanded_line != NULL)
	{
		i1 = 0;
		while (old_line != NULL && old_line[i1] != '\0')
		{
			expanded_line[i1] = old_line[i1];
			i1++;
		}
		i2 = 0;
		while (new_part[i2] != '\0' && i2 != nl)
		{
			expanded_line[i1 + i2] = new_part[i2];
			i2++;
		}
		expanded_line[i1 + i2] = '\0';
	}
	free(old_line);
	return (expanded_line);
}

void	offset(char *to_store, int find_nl)
{
	int	i;

	i = 0;
	while (to_store[i + find_nl] != '\0')
	{
		to_store[i] = to_store[i + find_nl];
		i++;
	}
	while (to_store[i] != '\0')
	{
		to_store[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	to_store[BUFFER_SIZE + 1];
	int			n;
	int			find_nl;

	line = NULL;
	if (read(fd, to_store, 0) == -1)
		return (NULL);
	find_nl = -1;
	while (find_nl == -1)
	{
		if (to_store[0] == '\0')
		{
			n = read(fd, to_store, BUFFER_SIZE);
			if (n == 0)
				break ;
			to_store[n] = '\0';
		}
		find_nl = find_newline(to_store);
		line = add_to_line(line, to_store, find_nl);
		offset(to_store, find_nl);
	}	
	return (line);
}
