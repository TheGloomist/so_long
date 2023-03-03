#include "so_long.h"

// // is it possible to solve a given map?
// bool check_if_solvable(t_so_long *data)
// {

// }

// are all characters valid, is there 1 exit, at least one collectable, 1 player?
void	check_characters(t_so_long *data)
{
	size_t	pos_len;
	size_t	i;
	char	**map;

	pos_len = 0;
	map = data->map_content;
	if (data->count_collectables < 1 || data->count_player != 1 || data->count_exits != 1)
		print_error("Invalid map. Must contain 1 exit, 1 player character and at least 1 collectable.\n");
	while (pos_len <= data->map_length)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (map[pos_len][i] == '1' || map[pos_len][i] == '0'|| map[pos_len][i] == 'P'|| map[pos_len][i] == 'E'|| map[pos_len][i] == 'C')
			{
				// printf("%c ", map[pos_len][i]);
				i++;
			}
			else
				print_error("Invalid map. Contains unknown characters.\n");
		}
		// printf("%zu ", pos_len);
		pos_len++;
	}
}

void	check_if_rectangular(t_so_long *data)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < data->map_length)
	{
		len = strlen(data->map_content[i]);
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
	// check_if_solvable(&data);

}

// TODO : 

// [] - check for invalid characters

// [X] - check if the map is rectangular (strs are equal length)

// [x] - check if there is a requered amount of valid characters (1 exit, at least 1 collectable, 1 player)

// [X] - check if map is walled off (top and bottom strings are walls, first and the last char in other strings is a wall)

// [] - exit and all of the collectables are reachable
