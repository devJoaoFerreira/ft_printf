/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_helpers2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:18 by jnovo-fe          #+#    #+#             */
/*   Updated: 2025/12/11 21:29:43 by jnovo-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	ft_dec_len(int x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	if (x == INT_MIN)
		len = 10;
	else if (x < 0)
		x *= -1;
	while (x > 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

int	ft_dec_len_unsigned(unsigned int x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	while (x > 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

int	ft_hexa_len(unsigned long x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}
