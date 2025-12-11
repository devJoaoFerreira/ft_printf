/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:15:04 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/09 13:56:38 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(t_str *str, t_flags *flags)
{
	unsigned long	addr;
	int				pad;
	int				len;

	addr = (unsigned long)va_arg(str->args, void *);
	len = ft_hexa_len(addr) + 2;
	if (addr == 0)
	{
		ft_convert_p_for_null(str, flags);
		return ;
	}
	pad = flags->width - len;
	if (!flags->left_justify && flags->padding == ' ')
		ft_padding(pad, str, flags);
	str->count += write(1, "0x", 2);
	if (flags->padding == '0')
		ft_padding(pad, str, flags);
	ft_recursive_print_lhexa(addr, str);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}

void	ft_convert_p_for_null(t_str *str, t_flags *flags)
{
	int	pad;

	pad = flags->width - 5;
	if (!flags->left_justify)
		ft_padding(pad, str, flags);
	str->count += write (1, "(nil)", 5);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}
