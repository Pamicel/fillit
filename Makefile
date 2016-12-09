# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:55:27 by apissier          #+#    #+#              #
#    Updated: 2016/12/09 13:58:38 by pamicel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfillit.a
CFLAGS += -Wall -Wextra -Werror
CC = cc
SRC = ft_putstr.c \
	ft_strlen.c \
	ft_read_file.c \
	ft_isvalid.c \
	ft_code.c \
	ft_realloc.c \
	ft_memalloc.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	    ar rcs $(NAME) $(OBJ)
clean:
	    rm -rf $(OBJ)

fclean: clean
	    rm -rf $(NAME)

re: fclean all
