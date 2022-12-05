/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:39 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/12/05 15:42:19 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hook(void *param)
{
	mlx_t			*mlx;
	int				speed;
	mlx_image_t		*g_img;
	// int		new_pos = 0;

	mlx = param;
	speed = ((mlx->width) / 100) + 5;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y = (g_img->instances[0].y - speed) % mlx->height;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y = (g_img->instances[0].y + speed) % mlx->height;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x = (g_img->instances[0].x - speed) % mlx->width;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x = (g_img->instances[0].x + speed) % mlx->width;
}

// int	main(void)
int	main(int argc, char **argv)
{
	t_so_long		data;
	mlx_image_t		*g_img;
	mlx_texture_t	*foxey;

	data.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!data.mlx)
		return (1);
	parsing(&data, argc, argv);
	foxey = mlx_load_png("./textures/Floffey_idle.png");
	g_img = mlx_texture_to_image(data.mlx, foxey);
	// my_func(&data);
	// data = my_func2(data);
	mlx_image_to_window(data.mlx, g_img, 0, 0);
	mlx_loop_hook(data.mlx, move_hook, data.mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
