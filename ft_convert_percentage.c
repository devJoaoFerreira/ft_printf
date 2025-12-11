/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:10:29 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/09 14:06:54 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* void	ft_convert_percentage(t_str *str, t_flags *flags)
{
	int		pad;

	pad = flags->width - 1;
	flags->padding = ' ';
	if (!flags->left_justify)
		ft_padding(pad, str, flags);
	str->count += write(1, "%%", 1);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
} */
void	ft_convert_percentage(t_str *str, t_flags *flags)
{
	flags->padding = ' ';
	str->count += write(1, "%%", 1);
}
