/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:52:02 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/09 13:56:28 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_u(t_str *str, t_flags *flags)
{
	unsigned int	x;
	int				len;
	int				pad;

	x = va_arg(str->args, unsigned int);
	len = ft_dec_len_unsigned(x);
	if (flags->precision == 0 && x == 0)
		len = 0;
	pad = flags->width - ft_max(len, flags->precision);
	if (!flags->left_justify && flags->padding == ' ')
		ft_padding(pad, str, flags);
	while (flags->precision > len++)
		str->count += write(1, "0", 1);
	if (!flags->left_justify && flags->padding == '0')
		ft_padding(pad, str, flags);
	if (flags->precision != 0 || x != 0)
		ft_recursive_unsigned_dec(x, str, flags);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}

void	ft_recursive_unsigned_dec(unsigned int x, t_str *str, t_flags *flags)
{
	if (x >= 10)
		ft_recursive_unsigned_dec(x / 10, str, flags);
	str->count += write(1, &DECIMAL_BASE[x % 10], 1);
}
