# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:59:20 by fnaciri-          #+#    #+#              #
#    Updated: 2020/11/26 14:09:42 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = minishell

D = -g

SRC =  ./src/*.c ./src/*/*.c

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC)  -g  main.c -L ./libft -lft $(SRC) -o $(NAME)

run:
	@./$(NAME)

debug:
	@$(CC)  -g  main.c -L ./libft -lft $(SRC) -o $(NAME) -fsanitize=address

clean:
	@rm -f $(NAME)
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	
re: fclean all

.PHONY: re fclean clean all
