/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:51:08 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/19 16:12:34 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_fill_str(const char *string, va_list args)
{
	t_str	*str;

	str = malloc(sizeof(t_str));
	if (!str)
		return (NULL);
	va_copy(str->args, args);
	str->string = string;
	str->count = 0;
	str->i = 0;
	return (str);
}

t_flags	*ft_fill_flags(t_flags *flags)
{
	flags = malloc(sizeof(t_flags));
	if (!flags)
	{
		return (NULL);
	}
	flags->left_justify = 0;
	flags->padding = ' ';
	flags->positive_sign = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->conversion = '\0';
	flags->prefix = 0;
	return (flags);
}
