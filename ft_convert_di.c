/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:28:57 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/11 21:31:48 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_di(t_str *str, t_flags *flags)
{
	int		x;
	int		len;
	int		pad;
	int		sign;

	x = va_arg(str->args, int);
	len = ft_dec_len(x);
	sign = 0;
	if ((flags->positive_sign && x >= 0) || flags->space || x < 0)
		sign = 1;
	if (flags->precision == 0 && x == 0)
		len = 0;
	pad = flags->width - ft_max(len, flags->precision) - sign;
	if (!flags->left_justify && flags->padding == ' ')
		ft_padding(pad, str, flags);
	ft_write_sign(x, str, flags);
	while (flags->precision > len++)
		str->count += write(1, "0", 1);
	if (!flags->left_justify && flags->padding == '0')
		ft_padding(pad, str, flags);
	if (flags->precision != 0 || x != 0)
		ft_recursive_signed_dec(x, str, flags);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}

void	ft_write_sign(int x, t_str *str, t_flags *flags)
{
	if (x < 0)
		str->count += write(1, "-", 1);
	else if (flags->space && !flags->positive_sign)
		str->count += write(1, " ", 1);
	else if (flags->positive_sign && x >= 0)
		str->count += write(1, "+", 1);
}

int	ft_handle_precision(t_flags *flags, int len)
{
	int	y;
	int	precision;

	y = 0;
	precision = flags->precision;
	if (precision == 0)
		return (0);
	if (precision > len && precision != -1)
	{
		while (precision > len)
		{
			precision--;
			y++;
		}
	}
	return (y);
}

void	ft_recursive_signed_dec(int x, t_str *str, t_flags *flags)
{
	if (x == INT_MIN)
	{
		str->count += write(1, "2", 1);
		x = 147483648;
	}
	if (x < 0)
		x *= -1;
	if (x >= 10)
		ft_recursive_signed_dec(x / 10, str, flags);
	str->count += write(1, &DECIMAL_BASE[x % 10], 1);
}
