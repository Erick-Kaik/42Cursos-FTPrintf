/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:54:50 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/20 20:14:29 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h> 
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *, ...);
int ft_format(char c, va_list list);
int	flag_str(char c, va_list list);
int flag_c(int letter);
int flag_s(char *str);
int flag_percentage();
int	flag_dec(char c, va_list list);
int flag_d(int number);
int flag_i(int number);
int flag_u(unsigned int number);
int flag_hex(char c, va_list list);
int flag_x(unsigned int number, int c);
int flag_p(unsigned long number);
char	*ft_convert_b10_to_b16(unsigned long n);
char	*ft_unsigned_itoa(unsigned int n);

#endif