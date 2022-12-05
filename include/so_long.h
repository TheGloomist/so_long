/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:47 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/12/05 16:31:52 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft.h"
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
	mlx_image_t	wall;
	mlx_image_t	floor;
	mlx_image_t	collectable;

} t_textures;

typedef struct s_so_long
{
	mlx_t	*mlx;
	size_t	map_width;
	size_t	map_lengh;
} t_so_long;

int		main(int argc, char **argv);
// int		main(void);
bool 	parsing(t_so_long *data, int argc, char **argv);
bool	extension_check(char **argv);
void	move_hook(void *param);

#endif