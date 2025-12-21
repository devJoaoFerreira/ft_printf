/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:40:51 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/18 14:32:58 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	if (!string)
		return (-1);
	va_start(args, string);
	count = ft_more_printf(args, string);
	va_end(args);
	return (count);
}

int	ft_more_printf(va_list args, const char *string)
{
	int		count;
	t_str	*str;

	str = ft_fill_str(string, args);
	if (!str)
		return (0);
	while (str->string[str->i])
	{
		if (str->string[str->i] == '%')
		{
			if (str->string[str->i + 1] == '\0')
				return (-1);
			str->i++;
			ft_parse(str);
		}
		else
		{
			write(1, &str->string[str->i++], 1);
			str->count++;
		}
	}
	count = str->count;
	free (str);
	return (count);
}
