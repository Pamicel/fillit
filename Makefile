# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:55:27 by apissier          #+#    #+#              #
#    Updated: 2016/12/09 14:17:16 by apissier         ###   ########.fr        #
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
	ft_memalloc.c \
	ft_memset.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	    ar rcs $(NAME) $(OBJ)
clean:
	    rm -rf $(OBJ)

fclean: clean
	    rm -rf $(NAME)

re: fclean all
