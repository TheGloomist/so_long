/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 17:42:04 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:31:03 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_so_long *data, int *fd)
{
	int		rd;
	char	buffer;

	rd = 1;
	while (rd != 0)
	{
		rd = read(*fd, &buffer, 1);
		if (rd < 0)
			print_error("Failed to read from the map.\n");
		if (buffer == '\n' && rd)
			data->map_length++;
		if (buffer == 'C')
			data->count_c++;
		if (buffer == 'P')
			data->count_player++;
		if (buffer == 'E')
			data->count_exits++;
		if (data->map_length == 1)
			data->map_width++;
	}
}

void	save_map(t_so_long *data, int *fd)
{
	size_t	i;

	data->map_length = 1;
	data->map_width = 0;
	data->count_c = 0;
	data->count_player = 0;
	data->count_exits = 0;
	read_map(data, fd);
	data->map_content = (char **)malloc((data->map_length) * sizeof(char *));
	close(*fd);
	*fd = open(data->map_name, O_RDONLY);
	if (*fd < 0)
		print_error("Failed to open the map.\n");
	i = 0;
	while (i < data->map_length)
	{
		data->map_content[i] = get_next_line(*fd);
		if (protected_strlen(data->map_content[i]) == data->map_width + 1)
			data->map_content[i][data->map_width] = '\0';
		i++;
	}
}

// check if map is stored in the .ber file
bool	extension_check(char **argv)
{
	size_t	len;

	len = protected_strlen(argv[1]);
	if (len < 4 || ft_strncmp((&argv[1][len - 4]), ".ber", len) != 0)
		return (false);
	return (true);
}

// open map
bool	parsing(t_so_long *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		print_error("Must be exactly one argument.\n");
	if (!extension_check(argv))
		print_error("Wrong file extention for the map.\n");
	data->map_name = argv[1];
	fd = open(data->map_name, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open the map.\n");
	save_map(data, &fd);
	close(fd);
	process_map(data);
	return (true);
}
