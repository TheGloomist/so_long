/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:39 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/04 18:58:28 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory_screen(t_so_long *data)
{
	mlx_texture_t	*victory;
	mlx_image_t		*sated;
	
	victory = mlx_load_png("textures/victory2.png");
	sated = mlx_texture_to_image(data->mlx, victory);
	mlx_image_to_window(data->mlx, sated, data->map_width / 2 * 100, \
	data->map_length / 2 * 100);
	mlx_put_string(data->mlx, "Dewicious :3", data->map_width / 2 * 100, \
	data->map_length / 2 * 100 + 50 );
	mlx_put_string(data->mlx, "Press any key to exit", data->map_width / 2 * 100, \
	data->map_length / 2 * 100 + 75);

}

bool	wall_check(t_so_long *data, int y, int x)
{
	if (data->map_content[y][x] == '1')
		return (false);
	return (true);
}

void	rotato_the_catto(t_so_long *data, enum keys facing)
{
	if (facing == MLX_KEY_W)
		data->character.player->pixels = data->character.W_player->pixels;
	if (facing == MLX_KEY_S)
		data->character.player->pixels = data->character.S_player->pixels;
	if (facing == MLX_KEY_D)
		data->character.player->pixels = data->character.D_player->pixels;
	if (facing == MLX_KEY_A)
		data->character.player->pixels = data->character.A_player->pixels;
}

void	count_and_collect(t_so_long *data, t_coords pos, enum keys facing, bool down)
{
	mlx_instance_t	hero_pos;
	size_t			i;

	hero_pos = data->character.player->instances[0];
	if ((size_t)hero_pos.x == pos.x && (size_t)hero_pos.y == pos.y)
		return ;
	data->number_of_steps++;
	ft_printf("You moved %u step(s).\n", data->number_of_steps);
	rotato_the_catto(data, facing);
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
		data->images.exit->pixels = data->images.open_door->pixels;
	if (data->map_content[pos.y / 100][pos.x / 100] == 'E')
	{
		if (data->ramens_left == 0)
		{
			victory_screen(data);
			if (down) 
				data->allow_exit = true;
		}
		else
		{
			mlx_put_string(data->mlx, "Can't leave yet.", pos.x, pos.y + 50 );
			mlx_put_string(data->mlx, "Need more ramen.", pos.x, pos.y + 75 );
		}
	}
}

void	movement(mlx_key_data_t keydata, t_so_long *data)
{
	mlx_image_t		*hero;
	t_coords		new;
	bool			down;

	down = (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS);
	hero = data->character.player;
	new.x = hero->instances[0].x;
	new.y = hero->instances[0].y;
	if (data->allow_exit && down)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_ESCAPE && down)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && down)
		new.y = (hero->instances[0].y - 100) % data->mlx->height;
	if (keydata.key == MLX_KEY_S && down)
		new.y = (hero->instances[0].y + 100) % data->mlx->height;
	if (keydata.key == MLX_KEY_A && down)
		new.x = (hero->instances[0].x - 100) % data->mlx->width;
	if (keydata.key == MLX_KEY_D && down)
		new.x = (hero->instances[0].x + 100) % data->mlx->width;
	if (wall_check(data, new.y / 100, new.x / 100) && down)
	{
		count_and_collect(data, new, keydata.key, down);
		hero->instances[0].x = new.x;
		hero->instances[0].y = new.y;
	}
}

int	main(int argc, char **argv)
{
	t_so_long		data;

	data.allow_exit = false;
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
