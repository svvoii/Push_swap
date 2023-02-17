# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 17:40:09 by sbocanci          #+#    #+#              #
#    Updated: 2023/02/17 17:51:16 by sbocanci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

src = sources/push_swap.c sources/stack.c sources/stack_manipulate.c sources/sort_small_stack.c sources/sort_push_swap.c sources/merge_sort.c sources/ft_split.c

#src_b = bonus/checker.c bonus/get_next_line.c bonus/sort_fct_bonus.c\
		bonus/sort_fct_rbonus.c bonus/utils_bonus.c bonus/util_2.c\
		bonus/utils_3.c

obj = $(src:.c=.o)

#obj_b = $(src_b:.c=.o)

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(obj) includes/push_swap.h
	@gcc $(flags) $(src) -o $(NAME)
	@echo ------Compiled Mondatory part-------


#bonus: $(NAME_B)

#$(NAME_B): $(src_b) $(obj_b) includes/push_swap_bonus.h
#	@gcc $(flags) $(src_b) -o $(NAME_B)
#	@echo ------Compiled Bonus part-------

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
	