/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:39 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/01 18:25:02 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	wall_check(t_so_long *data, int y, int x)
{
	if (data->map_content[y][x] == '1')
		return (false);
	return (true);
}

void	count_and_collect(t_so_long *data, t_coords pos, enum keys facing)
{
	mlx_instance_t	hero_pos;
	size_t			i;

	hero_pos = data->character.player->instances[0];
	if ((size_t)hero_pos.x == pos.x && (size_t)hero_pos.y == pos.y)
		return ;
	data->number_of_steps++;
	ft_printf("You moved %u step(s).\n", data->number_of_steps);
	if (facing == MLX_KEY_W)
		data->character.player->pixels = data->character.W_player->pixels;
	if (facing == MLX_KEY_S)
		data->character.player->pixels = data->character.S_player->pixels;
	if (facing == MLX_KEY_D)
		data->character.player->pixels = data->character.D_player->pixels;
	if (facing == MLX_KEY_A)
		data->character.player->pixels = data->character.A_player->pixels;
	if (data->map_content[pos.y / 100][pos.x / 100] == 'C')
	{
		i = 0;
		while (i < data->count_collectables)
		{
			if (data->images.collectable->instances[i].y == (int)pos.y \
			&& data->images.collectable->instances[i].x == (int)pos.x)
				data->images.collectable->instances[i].enabled = false;
			i++;
		}
		data->ramens_left--;
		data->map_content[pos.y / 100][pos.x / 100] = '0';
	}
	if (data->ramens_left == 0)
	{
		data->images.exit->pixels = data->images.open_door->pixels;
	}
	if (data->map_content[pos.y / 100][pos.x / 100] == 'E')
	{
		if (data->ramens_left == 0)
			mlx_close_window(data->mlx);
		else
			ft_printf("Can't leave yet. Need to collect %i more ramen(s)\n", (int)data->ramens_left);
	}
}

void	movement(mlx_key_data_t keydata, t_so_long *data)
{
	mlx_t			*mlx;
	mlx_image_t		*hero;
	t_coords		new;
	bool			down;

	down = (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS);
	mlx = data->mlx;
	hero = data->character.player;
	new.x = hero->instances[0].x;
	new.y = hero->instances[0].y;
	if (keydata.key == MLX_KEY_ESCAPE && down)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_W && down)
		new.y = (hero->instances[0].y - 100) % mlx->height;
	if (keydata.key == MLX_KEY_S && down)
		new.y = (hero->instances[0].y + 100) % mlx->height;
	if (keydata.key == MLX_KEY_A && down)
		new.x = (hero->instances[0].x - 100) % mlx->width;
	if (keydata.key == MLX_KEY_D && down)
		new.x = (hero->instances[0].x + 100) % mlx->width;
	if (wall_check(data, new.y / 100, new.x / 100) && down)
	{
		count_and_collect(data, new, keydata.key);
		hero->instances[0].x = new.x;
		hero->instances[0].y = new.y;
	}
}

int	main(int argc, char **argv)
{
	t_so_long		data;

	parsing(&data, argc, argv);
	data.mlx = mlx_init(data.map_width * 100, data.map_length * 100, "so_long", false);
	if (!data.mlx)
		return (1);
	data.number_of_steps = 0;
	get_images(&data);
	mlx_key_hook(data.mlx, (mlx_keyfunc)movement, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	while (data.map_length > 0)
	{
		data.map_length--;
		free(data.map_content[data.map_length]);
	}
	free(data.map_content);
	return (0);
}
