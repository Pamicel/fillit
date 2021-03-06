# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:55:27 by apissier          #+#    #+#              #
#    Updated: 2016/12/14 16:26:37 by pamicel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBNAME = libfillit.a
CFLAGS += -Wall -Wextra -Werror
CC = cc
SRC = ft_get_tetro.c \
	ft_read_file.c \
	ft_binary.c \
	ft_solve.c \
	ft_print_result.c
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBNAME)
			gcc $(FLAGS) -o $(NAME) ft_fillit.c -L . -lfillit -lft

$(LIBNAME): $(OBJ)
			ar rcs $(LIBNAME) $(OBJ)

clean:
			rm -rf $(OBJ)
			rm -rf $(LIBNAME)

fclean: clean
			rm -rf $(NAME)

re: fclean all
