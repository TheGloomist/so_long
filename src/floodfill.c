/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 15:25:53 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:25:07 by izaitcev      ########   odam.nl         */
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
		if (data->floodfill.collectables == data->count_c)
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
void	check_if_solvable(t_so_long *d)
{
	size_t		y;

	y = 0;
	d->floodfill.map_copy = (char **)malloc(sizeof(char *) * d->map_length);
	while (y < d->map_length)
	{
		d->floodfill.map_copy[y] = ft_strdup(d->map_content[y]);
		y++;
	}
	flood_fill(d, d->character.map.y, d->character.map.x);
	while (y > 0)
	{
		y--;
		free(d->floodfill.map_copy[y]);
	}
	free(d->floodfill.map_copy);
}
