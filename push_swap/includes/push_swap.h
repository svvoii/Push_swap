/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:51:54 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/13 14:15:13 by sbocanci         ###   ########.fr       */
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
}	t_stack;

void	print_array(int *arr, int len);

void	get_rand_nums(int *a, int len, int min, int max);
void	merge_sort(int *arr, int start, int end);
void	copy(int *from, int *to, int len);
t_stack	*create_stack(int c, int capacity);
void	fill_in_stack(t_stack *a, int *arr);
void	destroy_stack(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		push(t_stack *stack, int item);
int		pop(t_stack *stack, int *item);
void	swap(int *a, int *b, char c);
//int		peek(t_stack *stack, int *item);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three_nums(t_stack *st);

#endif