/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:54:34 by sv                #+#    #+#             */
/*   Updated: 2023/02/28 17:21:14 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	capacity;
	int	count;
	int	chunk;
}	t_stack;

// push_swap.c (main)
int		valid_argv(int ac, char **av);
int		unique_values(int *st, int size);
int		sorted(t_stack *st);
void	ft_quit(t_stack *st, int err);

void	print_array(int *arr, int size);
// stack.c
t_stack	*create_stacks_a_b(int capacity);
int		is_empty(t_stack *stack, char name);
void	atoi_str_to_stack(char **av, t_stack *stack);
long	ft_atoi(char *str, t_stack *stack);
// stack_manipulate.c
int		push(int item, t_stack *st, char name);
int		pop(int *item, t_stack *stack, char name);
void	swap(t_stack *st, int a, int b, char name);
void	rotate(t_stack *st, char name);
void	reverse_rotate(t_stack *st, char name);
// sort_small_stack.c
void	sort_small_stack(t_stack *st);
void	sort_three_nums(t_stack *st);
void	find_lowest_and_swap_or_rr(t_stack *st, char name, int i);
void	search_index_to_insert_b(t_stack *st, int value);
void	rotate_to_set_in_order_b(t_stack *st, int n);
/*
// chunk_sort.c
int		is_max(t_stack *st, int item);
int 	is_min(t_stack *st, char name, int item);
int		find_index(t_stack *st, char name, int item);
int		find_place_to_insert_b(t_stack *st, int item);
int		calc_rotations(t_stack *st);
void	calc_and_push_to_b(t_stack *st);

void	indexing(t_stack *st);
void	merge_sort(int *arr, int start, int end);

void	push_chunks_to_b(t_stack *st);

void	min_index(t_stack *st, char name, int *i);
int		condition_to_insert(t_stack *st, int item);
void	smart_push_back_to_a(t_stack *st);

void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);
// calc_moves.c
int	case_ra_rb(t_stack *st, int item);
int	case_rra_rrb(t_stack *st, int item);
int	case_rra_rb(t_stack *st, int item);
int	case_ra_rrb(t_stack *st, int item);
int	ra_rb(t_stack *st, int item);
int	ra_rrb(t_stack *st, int item);
int	rra_rrb(t_stack *st, int item);
int	rra_rb(t_stack *st, int item);
*/
// sort_push_swap.c
void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
void	smart_push_back_to_a(t_stack *st);
void	clac_r_in_a_for_each_b(t_stack *st, int *ra);
void	prepare_for_min_spin(t_stack *st, int *ra);
int		direction(int index, int size);
int		ra_vs_rra(int index, int size_a);
int		rb_vs_rrb(int index, int size_b);
void	min_a_vs_min_b(int *ra, int size, int *min_i, int *max_i);
void	direction_to_spin(t_stack *st, char name, int i);
int 	is_min(int *arr, int size, int item);
int 	is_max(int *arr, int size, int item);
int		min_index(int *arr, int size);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);
void	spin(t_stack *st, int spin_a, int a_direction, int spin_b, int b_direction);
void	bring_min_to_top(t_stack *st);

void	merge_sort(int *arr, int start, int end);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);

#endif
