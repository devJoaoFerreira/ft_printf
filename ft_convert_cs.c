/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:38:52 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/11 19:02:26 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_str *str, t_flags *flags)
{
	int		c;
	int		pad;

	c = va_arg(str->args, int);
	pad = flags->width - 1;
	flags->padding = ' ';
	if (!flags->left_justify)
		ft_padding(pad, str, flags);
	str->count += write(1, &c, 1);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}

void	ft_convert_s(t_str *str, t_flags *flags)
{
	char	*s;
	int		pad;
	int		len;
	int		i;

	s = va_arg(str->args, char *);
	len = ft_strlen(s);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (!s && (flags->precision < 0 || flags->precision > 5))
		len += 6;
	pad = flags->width - len;
	flags->padding = ' ';
	if (!flags->left_justify)
		ft_padding(pad, str, flags);
	if (!s && (flags->precision < 0 || flags->precision > 5))
		str->count += write(1, "(null)", 6);
	i = -1;
	while (s && s[++i] && i < len)
		str->count += write(1, &s[i], 1);
	if (flags->left_justify)
		ft_padding(pad, str, flags);
}
