# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamicel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 13:37:24 by pamicel           #+#    #+#              #
#    Updated: 2016/11/16 11:01:03 by pamicel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CFILES = 	ft_memalloc.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_strlen.c \
		 	ft_strcpy.c \
		 	ft_strncpy.c \
		 	ft_strdup.c \
		 	ft_memdel.c \
		 	ft_strnew.c \
		 	ft_strdel.c \
		 	ft_strclr.c \
		 	ft_memset.c \
		 	ft_putchar.c \
		 	ft_putstr.c \
			ft_putnbr.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_strncat.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_atoi.c \
			ft_strstr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c\
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_log10.c

OFILES = $(CFILES:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(NAME).a

$(NAME).a : $(OFILES)
	@ar rc $(NAME).a $(OFILES);
	@ranlib $(NAME).a

%.o : %.c
	@$(CC) -c -o $@ $(FLAGS) $<;

clean :
	@rm -f $(OFILES)

fclean :
	@rm -f $(OFILES) $(NAME).a

re: fclean all
