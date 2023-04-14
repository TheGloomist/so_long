/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 21:49:28 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:24:47 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// are all characters valid, is there 1 exit, 
// at least one collectable, 1 player?
void	check_characters(t_so_long *d)
{
	t_coords	pos;
	char		**map;

	pos.y = 0;
	map = d->map_content;
	while (pos.y < d->map_length)
	{
		pos.x = 0;
		while (pos.x < d->map_width)
		{
			if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '0' || \
			map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'C')
				pos.x++;
			else if (map[pos.y][pos.x] == 'P')
			{
				d->character.map.y = pos.y;
				d->character.map.x = pos.x;
				pos.x++;
			}
			else
				print_error("Invalid map. Contains unknown characters.\n");
		}
		pos.y++;
	}
}

void	check_if_rectangular(t_so_long *data)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < data->map_length)
	{
		len = protected_strlen(data->map_content[i]);
		if (len != data->map_width)
			print_error("Invalid map. Must be rectangular.\n");
		i++;
	}
}

// is map walled off and rectangular?
void	check_walls(t_so_long *data)
{
	char	**map;
	size_t	pos;

	map = data->map_content;
	pos = 0;
	while (pos < data->map_width)
	{
		if (map[0][pos] != '1' || map[data->map_length - 1][pos] != '1')
			print_error("Invalid map. Must be walled off.\n");
		pos++;
	}
	pos = 0;
	while (pos < data->map_length)
	{
		if (map[pos][0] != '1' || map[pos][data->map_width - 1] != '1')
			print_error("Invalid map. Must be walled off.\n");
		pos++;
	}
	return ;
}

// go through the map and check if all the requirements are met
void	process_map(t_so_long *data)
{
	check_if_rectangular(data);
	check_walls(data);
	if (data->count_c < 1 || data->count_player != 1 || data->count_exits != 1)
		print_error("Map must have 1 exit, 1 player and at least 1 col-able\n");
	check_characters(data);
	check_if_solvable(data);
	if (!data->floodfill.c_reachable || !data->floodfill.e_reachable)
		print_error("Invalid map. Can't reach exit or/and all collect-s.\n");
	data->ramens_left = data->count_c;
}
