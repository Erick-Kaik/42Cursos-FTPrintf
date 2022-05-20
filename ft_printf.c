/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:54:34 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/20 18:36:15 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int x;
	int y;
	va_list list;

	x = 0;
	y = 0;
	va_start(list, str);
	while (str[x] != '\0')
	{
		if (str[x] == '%' && ft_strchr("cspdiuxX%", str[x + 1]))
		{
			x++;
			y += ft_format(str[x], list);
			x++;
		}
		if (str[x] == '\0')
			break ;
		else if (str[x] == '%' && ft_strchr("cspdiuxX%", str[x + 1]))
			continue ;
		y += ft_putchar(str[x]);
		x++;
	}
	va_end(list);
	return (y);
}	

int ft_format(char c, va_list list)
{
	int value;

	value = 0;
	if (c == 'c' || c == 's' || c == '%')
		value += flag_str(c, list);
 	else if (c == 'd' || c == 'i' || c == 'u')
		value += flag_dec(c, list);
	else if (c == 'x' || c == 'X' || c == 'p')
		value += flag_hex(c, list);
	return (value);
}