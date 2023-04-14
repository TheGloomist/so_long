/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:18:40 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:49:06 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *error)
{
	ft_printf("%s", error);
	exit(0);
}

t_coords	translate_map_to_screen(t_so_long *data, t_coords to_translate)
{
	t_coords	ret;

	ret.x = to_translate.x * (data->mlx->width / data->map_width);
	ret.y = to_translate.y * (data->mlx->height / data->map_length);
	return (ret);
}

void	rotato_the_catto(t_so_long *data, enum keys facing)
{
	if (facing == MLX_KEY_W)
		data->character.player->pixels = data->character.w_player->pixels;
	if (facing == MLX_KEY_S)
		data->character.player->pixels = data->character.s_player->pixels;
	if (facing == MLX_KEY_D)
		data->character.player->pixels = data->character.d_player->pixels;
	if (facing == MLX_KEY_A)
		data->character.player->pixels = data->character.a_player->pixels;
}

bool	wall_check(t_so_long *data, int y, int x)
{
	if (data->map_content[y][x] == '1')
		return (false);
	return (true);
}
