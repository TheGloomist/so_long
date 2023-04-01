/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 21:49:15 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/01 18:11:06 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coords	translate_map_to_screen(t_so_long *data, t_coords to_translate)
{
	t_coords	ret;

	ret.x = to_translate.x * (data->mlx->width / data->map_width);
	ret.y = to_translate.y * (data->mlx->height / data->map_length);
	return (ret);
}

// pm - position on the map
// ps - position on the screen
void	put_floor(t_so_long *data)
{
	t_coords		pm;
	t_coords		ps;

	pm.y = 0;
	while (pm.y < data->map_length)
	{
		pm.x = 0;
		while (pm.x < data->map_width)
		{
			ps = translate_map_to_screen(data, pm);
			mlx_image_to_window(data->mlx, data->images.floor, \
			ps.x, ps.y);
			pm.x++;
		}
		pm.y++;
	}
}

void	put_wall(t_so_long *data)
{
	t_coords		pm;
	t_coords		ps;

	pm.y = 0;
	while (pm.y < data->map_length)
	{
		pm.x = 0;
		while (pm.x < data->map_width)
		{
			if (data->map_content[pm.y][pm.x] == '1')
			{
				ps = translate_map_to_screen(data, pm);
				mlx_image_to_window(data->mlx, data->images.wall, \
				ps.x, ps.y);
			}
			pm.x++;
		}
		pm.y++;
	}
}

void	put_rest(t_so_long *data)
{
	t_coords		pm;
	t_coords		ps;

	pm.y = 0;
	while (pm.y < data->map_length)
	{
		pm.x = 0;
		while (pm.x < data->map_width)
		{
			if (data->map_content[pm.y][pm.x] == 'C')
			{
				ps = translate_map_to_screen(data, pm);
				mlx_image_to_window(data->mlx, data->images.collectable, \
				ps.x, ps.y);
			}
			if (data->map_content[pm.y][pm.x] == 'E')
			{
				ps = translate_map_to_screen(data, pm);
				mlx_image_to_window(data->mlx, data->images.exit, \
				ps.x, ps.y);
			}
			pm.x++;
		}
		pm.y++;
	}
}

void	get_images(t_so_long *data)
{
	data->images.grass = mlx_load_png("./textures/grass3.png");
	data->images.floor = mlx_texture_to_image(data->mlx, data->images.grass);
	put_floor(data);
	data->images.stone = mlx_load_png("./textures/wall2.png");
	data->images.wall = mlx_texture_to_image(data->mlx, data->images.stone);
	put_wall(data);
	data->images.door = mlx_load_png("./textures/exit.png");
	data->images.exit = mlx_texture_to_image(data->mlx, data->images.door);
	data->images.open_door = mlx_load_png("./textures/open_door.png");
	data->images.ramen = mlx_load_png("./textures/ramen2.png");
	data->images.collectable = mlx_texture_to_image(data->mlx, data->images.ramen);
	put_rest(data);
	data->character.screen = translate_map_to_screen(data, data->character.map);
	get_cat_face(data);
	mlx_image_to_window(data->mlx, data->character.player, \
	data->character.screen.x, data->character.screen.y);
}

void	get_cat_face(t_so_long *data)
{
	data->character.W_player = mlx_load_png("./textures/cat_back.png");
	data->character.S_player = mlx_load_png("./textures/cat.png");
	data->character.A_player = mlx_load_png("./textures/cat_a.png");
	data->character.D_player = mlx_load_png("./textures/cat_d.png");
	data->character.player = mlx_texture_to_image(data->mlx, data->character.S_player);
}
