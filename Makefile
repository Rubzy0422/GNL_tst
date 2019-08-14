NAME = GNL_TST
CC = gcc
SRC =	main.c\
		get_next_line.c

INC =	-I ./

LIBS = libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = obj
OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) libft.a
	@$(CC) $(OBJS) -o $(NAME) $(FLAGS) $(LIBS)
	@printf "\e[33m[COMPILED] \e[32m%41s\e[39m\n" "$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(FLAGS) -c $^ -o $@ $(INC)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@printf "\e[33m[COMPILING] \e[32;1m%40s\n\e[39m"  "$(NAME)"
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "\e[31m %30s \e[39m\n" "[CLEANING $(NAME)]" 
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

reset: fclean
	@rm -rf libft
	@rm -rf src/get_next_line.c
	@rm -rf get_next_line.h

libft.a: libft
	@make -C libft

