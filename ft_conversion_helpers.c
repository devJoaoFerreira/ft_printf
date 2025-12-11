/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:53:22 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/11 21:20:23 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(int pad, t_str *str, t_flags *flags)
{
	while (pad > 0)
	{
		str->count += write(1, &flags->padding, 1);
		pad--;
	}
}

int	ft_max(int a, int b)
{
	return (a * (a > b) + b * (b >= a));
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_recursive_print_lhexa(unsigned long x, t_str *str)
{
	if (x >= 16)
		ft_recursive_print_lhexa(x / 16, str);
	str->count += write(1, &HEXADECIMAL_LBASE[x % 16], 1);
}

void	ft_recursive_print_uhexa(unsigned long x, t_str *str)
{
	if (x >= 16)
		ft_recursive_print_uhexa(x / 16, str);
	str->count += write(1, &HEXADECIMAL_UBASE[x % 16], 1);
}
