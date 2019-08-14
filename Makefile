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

NAME = GNL_TST
cc = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT := libft/libft.a

SRC = main.c \
      get_next_line.c


all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME):
	@$(CC) $(SRC) $(LIBFT) $(GNL) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
.PHONY: clean fclean all re
