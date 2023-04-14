/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 21:49:15 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:49:33 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_textures	*image;

	image = &(data->images);
	image->grass = mlx_load_png("./textures/grass3.png");
	image->floor = mlx_texture_to_image(data->mlx, image->grass);
	put_floor(data);
	image->stone = mlx_load_png("./textures/wall2.png");
	image->wall = mlx_texture_to_image(data->mlx, image->stone);
	put_wall(data);
	image->door = mlx_load_png("./textures/exit.png");
	image->exit = mlx_texture_to_image(data->mlx, image->door);
	free(image->exit->pixels);
	image->exit->pixels = image->door->pixels;
	image->open_door = mlx_load_png("./textures/open_door.png");
	image->ramen = mlx_load_png("./textures/ramen2.png");
	image->collectable = mlx_texture_to_image(data->mlx, image->ramen);
	put_rest(data);
	data->character.screen = translate_map_to_screen(data, data->character.map);
	get_cat_face(data);
	mlx_image_to_window(data->mlx, data->character.player, \
	data->character.screen.x, data->character.screen.y);
}

void	get_cat_face(t_so_long *data)
{
	data->character.w_player = mlx_load_png("./textures/cat_back.png");
	data->character.s_player = mlx_load_png("./textures/cat.png");
	data->character.a_player = mlx_load_png("./textures/cat_a.png");
	data->character.d_player = mlx_load_png("./textures/cat_d.png");
	data->character.player = mlx_texture_to_image(data->mlx, \
	data->character.s_player);
	free(data->character.player->pixels);
	data->character.player->pixels = data->character.s_player->pixels;
}
