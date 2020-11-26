# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:59:20 by fnaciri-          #+#    #+#              #
#    Updated: 2020/11/26 11:02:53 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = minishell

D = -g

SRC =  ./src/*.c ./src/*/*.c

all: $(NAME)

$(NAME):
	@$(C) -g -o $(NAME) main.c $(SRC)

run:
	@./$(NAME)
debug:
	@$(C) $(FLAGS) -o $(NAME) main.c $(SRC) -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
