/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 17:42:04 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/12/05 16:33:05 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// save map as an array of strings (char **)

// read the map
void	process_map(t_so_long *data, int fd)
{
	int	ret;

}

// print an error and exit the program
void	print_error(const char *error)
{
	ft_printf(error);
	exit(0);
}

// check if map is stored in the .ber file
bool	extension_check(char **argv)
{
	int	len;

	len = strlen(argv[1]); // replace with ft_strlen
	if (len < 4 || strcmp((&argv[1][len - 4]), ".ber") != 0) // replace with ft_strcmp 
		return (false);
	return (true);
}

// open map
bool	parsing(t_so_long *data, int argc, char **argv)
{
	int	fd;

	(void)data; // TODO: remove once you use data
	if (argc != 2)
		print_error("Must be exactly one argument.\n");
	if (!extension_check(argv))
		print_error("Wrong file extention for the map.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Failed to open the map.\n");
	process_map(&data, fd);
	return (true);
}



// check for invalid characters

// check if the map is rectangular (strs are equal length)

// check if there is a requered amount of valid characters (1 exit, at least 1 collectable, 1 player)

// check if map is walled off (top and bottom strings are walls, first and the last char in other strings is a wall)

// exit and all of the collectables are reachable


