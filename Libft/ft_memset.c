/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:51:59 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/06 05:03:54 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t size)
{
	size_t	x;
	char	*temp;

	x = 0;
	temp = (char *)str;
	if (str == NULL)
		return (NULL);
	while (x < size)
	{
		temp[x] = c;
		x++;
	}
	return (temp);
}
