/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 21:49:28 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/04 18:55:05 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_so_long *data, int y, int x)
{
	if (data->floodfill.map_copy[y][x] == '1')
		return ;
	if (data->floodfill.map_copy[y][x] == 'C')
	{
		data->floodfill.collectables++;
		if (data->floodfill.collectables == data->count_collectables)
			data->floodfill.c_reachable = true;
	}
	if (data->floodfill.map_copy[y][x] == 'E')
	{
		data->floodfill.e_reachable = true;
		return ;
	}
	data->floodfill.map_copy[y][x] = '1';
	flood_fill(data, y, x + 1);
	flood_fill(data, y, x - 1);
	flood_fill(data, y + 1, x);
	flood_fill(data, y - 1, x);
}

// // is it possible to solve a given map?
void	check_if_solvable(t_so_long *data)
{
	size_t		y;

	y = 0;
	data->floodfill.map_copy = (char **)malloc(sizeof(char *) * data->map_length);
	while (y < data->map_length)
	{
		data->floodfill.map_copy[y] = ft_strdup(data->map_content[y]);
		y++;
	}
	flood_fill(data, data->character.map.y, data->character.map.x);
	while (y > 0)
	{
		y--;
		free(data->floodfill.map_copy[y]);
	}
	free(data->floodfill.map_copy);
}

// are all characters valid, is there 1 exit, 
// at least one collectable, 1 player?
void	check_characters(t_so_long *data)
{
	size_t	y;
	size_t	x;
	char	**map;

	y = 0;
	map = data->map_content;
	if (data->count_collectables < 1 || data->count_player != 1 \
	|| data->count_exits != 1)
	{
		ft_printf(\
		"Map must have 1(%i) exit, 1(%i) player character and at least 1(%i) col-table.\n",\
		(int)data->count_exits, (int)data->count_player, (int)data->count_collectables);
		exit(0);
	}
	while (y < data->map_length)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (map[y][x] == '1' || map[y][x] == '0')
				x++;
			else if (map[y][x] == 'E' || map[y][x] == 'C')
				x++;
			else if (map[y][x] == 'P')
			{
				data->character.map.y = y;
				data->character.map.x = x;
				x++;
			}
			else
				print_error("Invalid map. Contains unknown characters.\n");
		}
		y++;
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
	check_characters(data);
	check_if_solvable(data);
	if (!data->floodfill.c_reachable || !data->floodfill.e_reachable)
		print_error("Invalid map. Can't reach an exit or/and all the collectables.\n");
	data->ramens_left = data->count_collectables;
}
