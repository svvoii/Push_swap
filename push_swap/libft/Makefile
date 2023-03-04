# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:15:30 by sbocanci          #+#    #+#              #
#    Updated: 2023/03/04 17:09:36 by sbocanci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=$(CC) -c $(CFLAGS)
CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=libft.a

SRC=ft_bzero.c ft_isdigit.c ft_isspace.c ft_memcpy.c\
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_streq.c ft_strjoin.c\
	ft_strlen.c ft_strncmp.c ft_substr.c


OBJ=$(SRC:.c=.o)

all: $(NAME)
$(NAME):
	$(C) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
