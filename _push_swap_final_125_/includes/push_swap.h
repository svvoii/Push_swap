/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:54:34 by sv                #+#    #+#             */
/*   Updated: 2023/03/06 14:21:20 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	char	**input_str;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		capacity;
	int		chunk;
}	t_stack;

/* push_swap.c */
char	**copy_to_2d_str_arr(int ac, char **av, int *count);
int		unique_values(t_stack *st);
int		sorted(t_stack *st);
void	free_and_quit(t_stack *st, int ac, int err);
void	print_instruction(char *s1, char s2);
/* stack.c */
t_stack	*create_stacks_a_b(t_stack *st, int capacity);
void	atoi_str_to_stack(t_stack *st, int ac);
long	ft_atoi(char *s, t_stack *st, int ac);
void	merge_sort(int *arr, int start, int end);
/* stack_instructions.c */
void	push(int item, t_stack *st, char name, int print);
void	pop(int *item, t_stack *stack, char name);
void	swap(t_stack *st, char name, int print);
void	rotate(t_stack *st, char name, int print);
void	reverse_rotate(t_stack *st, char name, int print);
/* sort_psw_00.c */
void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
void	smart_push_back_to_a(t_stack *st);
void	clac_r_in_a_for_each_b(t_stack *st, int *ra, int *rb);
void	calc_rotations(int *ra, int *rb, int *rotations, int size);
/* sort_psw_01.c */
int		abs(int n);
void	spin(t_stack *st, int *ra, int *rb, int i);
void	rr_ra_rb(t_stack *st, int a, int b);
void	rrr_rra_rrb(t_stack *st, int a, int b);
void	bring_min_to_top(t_stack *st);
/* sort_psw_02.c */
void	sort_three_nums(t_stack *st);
int		min_index(int *arr, int size);
int		is_min(int *arr, int size, int item);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);

#endif
