/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:36:32 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/21 18:27:30 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//libraries used

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//struct that hold the args list, the string index and count of chars printed;

typedef struct s_str
{
	va_list		args;
	const char	*string;
	size_t		i;
	size_t		count;
}	t_str;

//struct that holds info about flags, width and precision

typedef struct s_flags
{
	int		left_justify;
	char	padding;
	int		positive_sign;
	int		space;
	int		width;
	int		precision;
	char	conversion;
	int		prefix;
}	t_flags;

//defined macros for the bases used(decimal, lhexadecimal and uhexadecimal)

# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_UBASE "0123456789ABCDEF"
# define HEXADECIMAL_LBASE "0123456789abcdef"

//printf main functions

int		ft_printf(const char *string, ...);
int		ft_more_printf(va_list args, const char *string);

//parsing functions

void	ft_parse(t_str *str);
void	ft_parse_flags(t_str *str, t_flags *flags);
void	ft_parse_width(t_str *str, t_flags *flags);
void	ft_parse_precision(t_str *str, t_flags *flags);
void	ft_parse_conversions(t_str *str, t_flags *flags);

//conversion functions

void	ft_convert_c(t_str *str, t_flags *flags);
void	ft_convert_s(t_str *str, t_flags *flags);
void	ft_convert_p(t_str *str, t_flags *flags);
void	ft_convert_di(t_str *str, t_flags *flags);
void	ft_convert_u(t_str *str, t_flags *flags);
void	ft_convert_x(t_str *str, t_flags *flags);
void	ft_convert_percentage(t_str *str);

//helper functions for conversions

size_t	ft_strlen(const char *s);
void	ft_padding(int pad, t_str *str, t_flags *flags);
int		ft_hexa_len(unsigned long x);
int		ft_strchr(const char *s, int c);
int		ft_dec_len(int x);
int		ft_dec_len_unsigned(unsigned int x);
int		ft_max(int a, int b);
void	ft_recursive_print_lhexa(unsigned long addr, t_str *str);
void	ft_recursive_print_uhexa(unsigned long addr, t_str *str);
void	ft_convert_p_for_null(t_str *str, t_flags *flags);
void	ft_recursive_signed_dec(int x, t_str *str, t_flags *flags);
void	ft_write_sign(int x, t_str *str, t_flags *flags);
void	ft_recursive_unsigned_dec(unsigned int x, t_str *str, t_flags *flags);
void	ft_which_hexa(unsigned int x, t_str *str);
void	ft_write_prefix(t_str *str);

//functions to fill structs

t_str	*ft_fill_str(const char *string, va_list args);
t_flags	*ft_fill_flags(t_flags *flags);

#endif