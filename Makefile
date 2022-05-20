# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 14:54:36 by ekaik-ne          #+#    #+#              #
#    Updated: 2022/05/19 18:44:53 by ekaik-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
Libft = libft.a
SRCS = ft_flag_dec.c ft_flag_hex.c ft_flag_str.c ft_printf.c ft_printf_utils.c
OBJ = ${SRCS:.c=.o}

.PHONY = all clean fclean re

all: ${NAME} clean

${NAME}: $(Libft) $(OBJ)
	@ar -rc ${NAME} $(OBJ)

${Libft}: 
	@make -s -C Libft/
	@cp Libft/libft.a .
	@mv libft.a $(NAME) 

%.o: %.c
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all