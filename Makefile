# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 14:42:53 by vkovsh            #+#    #+#              #
#    Updated: 2017/12/05 14:10:42 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/ $(LIB_PATH)/includes/ 
OBJ_PATH = ./obj/
LIB_PATH = ./libft/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME = fillit.c		\
		   error.c		\
		   input.c		\
		   move.c		\
		   optimiser.c	\
		   readfile.c	\
		   solve.c		\
		   square.c		\
		   tetramino.c 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft
	@echo "Compiling" [ $(NAME) ]


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj Fillit..."

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove..." [ $(NAME) ]

re: fclean all
