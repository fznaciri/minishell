# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 14:56:26 by fnaciri-          #+#    #+#              #
#    Updated: 2020/12/01 10:25:16 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strndup.c \

SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \


OBJ_B = $(SRC_B:.c=.o)

OBJ = $(SRC:.c=.o)

all : $(NAME)

bonus : 
	@$(CC) $(FLAGS) -c $(SRC_B)
	@ar rc $(NAME) $(OBJ_B)
	@ranlib $(NAME)

$(NAME) : 
	@$(CC) $(FLAGS) -c $(SRC) $(SRC_B)
	@ar rc $(NAME) $(OBJ) $(OBJ_B)
	@ranlib $(NAME)

clean :
	@rm -f ft_*.o

fclean : clean
	@rm -f $(NAME)

re : fclean clean all
