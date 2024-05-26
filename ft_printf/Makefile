# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:51:40 by mskhairi          #+#    #+#              #
#    Updated: 2024/05/22 15:30:37 by mskhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putnbr.c ft_putnbr_u.c ft_putchar.c ft_putstr.c ft_putadd.c ft_puthexa.c  ft_printf.c 
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJ}

fclean:
	@rm -rf ${NAME} ${OBJ}

re: fclean all