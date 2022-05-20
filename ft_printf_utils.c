/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:00:05 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/19 22:29:20 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_size_itoa(size_t *value, size_t *size, unsigned int n);
static int ft_size(unsigned long n);

char	*ft_unsigned_itoa(unsigned int n)
{
	size_t	value;
	size_t	size;
	char	*temp;

	value = 0;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	ft_size_itoa(&value, &size, n);
	temp = (char *)ft_calloc(size + 1, sizeof(char));
	if (temp == NULL)
		return (0);
	size--;
	while (value > 0)
	{
		temp[size--] = value % 10 + '0';
		value /= 10;
	}
	return (temp);
}

static void	ft_size_itoa(size_t *value, size_t *size, unsigned int n)
{
	*value = n;
	while (n != 0)
	{
		n /= 10;
		(*size)++;
	}
}

char	*ft_convert_b10_to_b16(unsigned long n)
{
	int		len;
	char	*temp;
	char	*base16;

	if (n != 0)
		len = ft_size(n);
	else
		return (NULL);
	base16 = "0123456789abcdef";
	temp = malloc(len + 1 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[len--] = '\0';
	while (n >= 16)
	{
		temp[len--] = base16[n % 16];
		n /= 16;
	}
	if (n < 16)
		temp[len] = base16[n];
	return (temp);
}


static int ft_size(unsigned long n)
{
	int len;

	len = 0;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	if (n < 16)
		len++;
	return (len);
}