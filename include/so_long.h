/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:47 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/03/10 17:11:55 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "printf.h"
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
	mlx_image_t	exit;

} t_textures;

typedef struct s_floodfill
{
	char	**map_copy;
	size_t	collectables;
	bool	e_reachable;
	bool	c_reachable;
} t_floodfill;

typedef struct s_so_long
{
	mlx_t		*mlx;
	size_t		map_width;
	size_t		map_length;
	size_t		count_collectables;
	size_t		count_player;
	size_t		count_exits;
	char		*map_name;
	char		**map_content;
	t_player	character;
	t_floodfill	floodfill;
} t_so_long;

int		main(int argc, char **argv);
bool 	parsing(t_so_long *data, int argc, char **argv);
bool	extension_check(char **argv);
void	move_hook(void *param);
void	process_map(t_so_long *data);
void	print_error(const char *error);

#endif