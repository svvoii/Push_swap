# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sv <sv@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 17:40:09 by sbocanci          #+#    #+#              #
#    Updated: 2023/03/05 08:20:14 by sv               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

#LIBFT_DIR=./libft
#LIBFT=$(LIBFT_DIR)/libft.a

src = sources/push_swap.c sources/stack.c sources/stack_instructions.c sources/sort_psw_00.c sources/sort_psw_01.c sources/sort_psw_02.c sources/ft_split.c

#src_b = sources/checker.c sources/gnl_01.c sources/gnl_02.c sources/ft_split.c
#src_b = bonus/checker.c bonus/get_next_line.c bonus/sort_fct_bonus.c\
		bonus/sort_fct_rbonus.c bonus/utils_bonus.c bonus/util_2.c\
		bonus/utils_3.c

obj = $(src:.c=.o)

#obj_b = $(src_b:.c=.o)
#obj_b = $(src_b:.c=.o)

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(obj) includes/push_swap.h #$(LIBFT)
	@gcc $(flags) $(src) -o $(NAME)
	@echo ------Compiled Mondatory part-------

#$(LIBFT):
#	make -C $(LIBFT_DIR)
#	cp $(LIBFT) $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(src_b) $(obj_b) includes/checker.h includes/get_next_line.h
	@gcc $(flags) $(src_b) -o $(NAME_B)
	@echo ------Compiled Bonus part-------

%.o: %.c
	@gcc -c $< -o $@
	@echo ------Compiling Objects files-------

clean:
	@rm -rf $(obj) $(obj_b)
	@echo ------Deleting Objects Files-------

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@echo ------Deleting Output Files-------

re: fclean all
	