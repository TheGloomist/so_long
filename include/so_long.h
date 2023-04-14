/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:17:47 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/04/14 16:51:40 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "printf.h"
# define WIDTH 2000
# define HEIGHT 1000

typedef struct s_coords
{
	size_t	x;
	size_t	y;
}	t_coords;

typedef struct s_player
{
	mlx_image_t		*player;
	mlx_texture_t	*w_player;
	mlx_texture_t	*a_player;
	mlx_texture_t	*s_player;
	mlx_texture_t	*d_player;
	t_coords		map;
	t_coords		screen;
}	t_player;

typedef struct s_textures
{
	mlx_texture_t	*grass;
	mlx_texture_t	*stone;
	mlx_texture_t	*door;
	mlx_texture_t	*open_door;
	mlx_texture_t	*ramen;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectable;
	mlx_image_t		*exit;
	mlx_image_t		*open_exit;
}	t_textures;

typedef struct s_floodfill
{
	char	**map_copy;
	size_t	collectables;
	bool	e_reachable;
	bool	c_reachable;
}	t_floodfill;

typedef struct s_so_long
{
	mlx_t			*mlx;
	size_t			map_width;
	size_t			map_length;
	size_t			count_c;
	size_t			ramens_left;
	size_t			count_player;
	size_t			count_exits;
	char			*map_name;
	char			**map_content;
	t_player		character;
	t_floodfill		floodfill;
	t_textures		images;
	unsigned int	number_of_steps;
	bool			allow_exit;
}	t_so_long;

int			main(int argc, char **argv);
bool		parsing(t_so_long *data, int argc, char **argv);
bool		extension_check(char **argv);
bool		wall_check(t_so_long *data, int y, int x);
void		movement(mlx_key_data_t keydata, t_so_long *data);
void		process_map(t_so_long *data);
void		print_error(const char *error);
void		get_images(t_so_long *data);
void		get_cat_face(t_so_long *data);
void		rotato_the_catto(t_so_long *data, enum keys facing);
t_coords	translate_map_to_screen(t_so_long *data, t_coords to_translate);
void		check_if_solvable(t_so_long *d);

#endif
