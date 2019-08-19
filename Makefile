# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 10:52:30 by rengelbr          #+#    #+#              #
#    Updated: 2019/08/19 20:21:43 by rengelbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#LIB = libftprintf.a
LIB = libft/libft.a
NAME = printf_test
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

all:
	gcc -Wall -Werror -Wextra $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
