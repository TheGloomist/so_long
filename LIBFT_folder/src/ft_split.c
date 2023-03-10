/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 19:01:35 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/04/30 22:16:01 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		w_count++;
		while (s[i] == c)
			i++;
	}
	return (w_count);
}

int	get_length(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char	**handle_error(char **s, int const len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i])
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**split_s(
	char const	*s,
	char		**str_array,
	char const	c,
	int const	w_count)
{
	int	i;
	int	j;
	int	w_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		w_len = get_length(&s[i], c);
		str_array[j] = ft_substr(s, i, w_len);
		if (str_array[j] == NULL)
			return (handle_error(str_array, w_count));
		j++;
		i += w_len;
	}
	return (str_array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		w_count;

	if (s == NULL)
		return (NULL);
	w_count = word_count(s, c);
	str_array = ft_calloc(1, (w_count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		str_array[0] = NULL;
		return (str_array);
	}
	if (c == '\0')
	{
		str_array[0] = ft_strdup(s);
		str_array[1] = NULL;
		return (str_array);
	}
	return (split_s(s, str_array, c, w_count));
}
