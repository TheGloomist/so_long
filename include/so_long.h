/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:47 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/12/01 16:57:50 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
// # include "libft.h"
# define WIDTH 2000
# define HEIGHT 1000

typedef struct s_player
{
	mlx_image_t	player;
	int			x;
	int			y;
} t_player;

typedef struct s_textures
{

} t_textures;

typedef struct s_so_long
{
	mlx_t	*mlx;
} t_so_long;

int	main (int argc, char **argv);
void	move_hook(void *param);

#endif