/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:40:08 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/09 14:09:55 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(t_str *str)
{
	t_flags	*flags;

	flags = NULL;
	flags = ft_fill_flags(flags);
	ft_parse_flags(str, flags);
	ft_parse_width(str, flags);
	ft_parse_precision(str, flags);
	ft_parse_conversions(str, flags);
	str->i++;
	free(flags);
}

void	ft_parse_flags(t_str *str, t_flags *flags)
{
	int		j;
	char	*flag_chars;

	flag_chars = "-0# +";
	j = 0;
	while (ft_strchr(flag_chars, str->string[str->i]) && str->string[str->i])
	{
		if (str->string[str->i] == '-')
		{
			flags->left_justify = 1;
			flags->padding = ' ';
		}
		else if (str->string[str->i] == '0' && !flags->left_justify)
			flags->padding = '0';
		else if (str->string[str->i] == '#')
			flags->prefix = 1;
		else if (str->string[str->i] == ' ')
			flags->space = 1;
		else if (str->string[str->i] == '+')
			flags->positive_sign = 1;
		str->i++;
	}
}

void	ft_parse_width(t_str *str, t_flags *flags)
{
	int	width;

	width = 0;
	if (str->string[str->i] >= '0' && str->string[str->i] <= '9')
	{
		while (str->string[str->i] >= '0' && str->string[str->i] <= '9')
		{
			width = (width * 10) + (str->string[str->i] - '0');
			str->i++;
		}
	}
	flags->width = width;
}

void	ft_parse_precision(t_str *str, t_flags *flags)
{
	int	precision;

	precision = -1;
	if (str->string[str->i] == '.')
	{
		str->i++;
		if (str->string[str->i] >= '0' && str->string[str->i] <= '9')
		{
			precision = 0;
			while (str->string[str->i] >= '0' && str->string[str->i] <= '9')
			{
				precision = (precision * 10) + (str->string[str->i] - '0');
				str->i++;
			}
		}
		else
			precision = 0;
		if (ft_strchr("diuxX", str->string[str->i]))
			flags->padding = ' ';
	}
	flags->precision = precision;
}

void	ft_parse_conversions(t_str *str, t_flags *flags)
{
	if (str->string[str->i] == 'c')
		ft_convert_c(str, flags);
	if (str->string[str->i] == 's')
		ft_convert_s(str, flags);
	if (str->string[str->i] == 'p')
		ft_convert_p(str, flags);
	if (str->string[str->i] == 'd' || str->string[str->i] == 'i')
		ft_convert_di(str, flags);
	if (str->string[str->i] == 'u')
		ft_convert_u(str, flags);
	if (str->string[str->i] == 'x' || str->string[str->i] == 'X')
		ft_convert_x(str, flags);
	if (str->string[str->i] == '%')
		ft_convert_percentage(str, flags);
}
