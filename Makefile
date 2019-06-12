# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 10:18:08 by rcoetzer          #+#    #+#              #
#    Updated: 2019/06/12 11:22:05 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= tst
cc = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT := ./libft/libft.a
GNL = ./get_next_line.c
SRC = main.c

make:
	@$(MAKE) -C libft
	@$(CC) $(SRC) $(LIBFT) $(GNL) $(CFLAGS) -o $(NAME)

all: make

clean:
	@make clean -C libft
	@rm -rf *.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf ./libft ./get_next_line.c ./get_next_line.h

re: fclean all
.PHONY: clean fclean all re
