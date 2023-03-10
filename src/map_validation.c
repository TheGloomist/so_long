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
void check_if_solvable(t_so_long *data)
{
	
	// size_t		i;
	size_t		y;

	// i = 0;
	y = 0;
	data->floodfill.map_copy = (char **)malloc(sizeof(char *) * data->map_length);
	while (y < data->map_length)
	{
		data->floodfill.map_copy[y] = ft_strdup(data->map_content[y]);
		// printf("%s\n", data->floodfill.map_copy[y]);
		y++;
	}
	// printf("player y pos is: %i, player x pos is: %i\n", data->character.y, data->character.x);
	flood_fill(data, data->character.y, data->character.x);

}

// are all characters valid, is there 1 exit, at least one collectable, 1 player?
void	check_characters(t_so_long *data)
{
	size_t	y;
	size_t	x;
	char	**map;

	y = 0;
	map = data->map_content;
	if (data->count_collectables < 1 || data->count_player != 1 || data->count_exits != 1)
		print_error("Invalid map. Must contain 1 exit, 1 player character and at least 1 collectable.\n");
	while (y < data->map_length)
	{
		x = 0;
		while (x < data->map_width)
		{
			// printf("checking line: %zu, map width is : %zu, i is: %zu\n", pos_len, data->map_width, i);
			if (map[y][x] == '1' || map[y][x] == '0')
			{
				// printf("%c ", map[pos_len][i]);
				x++;
			}
			else if (map[y][x] == 'E'|| map[y][x] == 'C')
				x++;
			else if (map[y][x] == 'P')
			{
				data->character.y = y;
				data->character.x = x;
				x++;
			}
			else
				print_error("Invalid map. Contains unknown characters.\n");
		}
		// printf("%zu ", pos_len);
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
		if (len != data->map_width){
			// printf("%zu, %zu on line %zu\n", data->map_width, len, i);
			// printf("%s", data->map_content[i]);
			print_error("Invalid map. Must be rectangular.\n");
		}
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
}

// TODO : 

// [x] - check for invalid characters

// [X] - check if the map is rectangular (strs are equal length)

// [x] - check if there is a requered amount of valid characters (1 exit, at least 1 collectable, 1 player)

// [X] - check if map is walled off (top and bottom strings are walls, first and the last char in other strings is a wall)

// [x] - exit and all of the collectables are reachable
