/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:51:54 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/17 12:33:12 by sbocanci         ###   ########.fr       */
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
}	t_stack;

// push_swap.c (main)
int		valid_argv(int ac, char **av);
int		unique_values(int *st, int size);
int		sorted(t_stack *st);
void	ft_quit(t_stack *st, int err);
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
// sort_push_swap.c
void	indexing(t_stack *st);
void	merge_sort(int *arr, int start, int end);
void	push_chunks_to_b(t_stack *st);
void	rotate_b_for_proper_insert(t_stack *st, int item);
void	push_swap_to_b(t_stack *st);
void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

void	print_array(int *arr, int size);
#endif