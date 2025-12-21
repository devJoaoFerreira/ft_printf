/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:25:47 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/19 16:13:37 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_x(t_str *str, t_flags *flags)
{
	unsigned int	x;
	int				len;
	int				pad;

	x = va_arg(str->args, unsigned int);
	len = ft_hexa_len(x);
	if (flags->precision == 0 && x == 0)
		len = 0;
	pad = flags->width - ft_max(len, flags->precision);
	pad -= 2 * flags->prefix * (x != 0);
	if (!flags->left_justify && flags->padding == ' ')
		ft_padding(pad, str, flags);
	if (flags->prefix && x != 0)
		ft_write_prefix(str);
	while (flags->precision > len++)
		str->count += write(1, "0", 1);
	if (!flags->left_justify && flags->padding == '0')
		ft_padding(pad, str, flags);
	if (flags->precision != 0 || x != 0)
		ft_which_hexa(x, str);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}

void	ft_which_hexa(unsigned int x, t_str *str)
{
	if (str->string[str->i] == 'x')
		ft_recursive_print_lhexa(x, str);
	else
		ft_recursive_print_uhexa(x, str);
}

void	ft_write_prefix(t_str *str)
{
	if (str->string[str->i] == 'x')
		str->count += write(1, "0x", 2);
	else if (str->string[str->i] == 'X')
		str->count += write(1, "0X", 2);
}
