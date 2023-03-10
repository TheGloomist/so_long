/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 16:31:44 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/03/07 18:24:59 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	prntf_strlen(char *str);
int	print_str(char *str);
int	print_char(int c);
int	print_nbr(long int n);
int	print_unsigned_dec(unsigned int n);
int	print_lhex(unsigned long n);
int	print_uphex(unsigned int n);

#endif