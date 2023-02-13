/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/13 13:45:27 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Allocating memory for a structure and for int arr of given capacity
t_stack	*create_stacks_a_b(t_stack *st, int capacity)
{
	if (capacity <= 0)
		return (NULL);
	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->a = malloc(sizeof(int) * capacity);
	if (!st->a)
	{
		free(st);
		return (NULL);
	}
	st->b = malloc(sizeof(int) * capacity);
	if (!st->b)
	{
		free(st->a);
		free(st);
		return (NULL);
	}
	st->capacity = capacity;
	st->size_a = 0;
	st->size_b = 0;
	return (st);
}

// Filling in the stack from int arr. First element on top/last in arr
void	fill_in_stack_a(t_stack *st, int *arr)
{
	int	i;

	i = st->capacity;
	while (--i >= 0)
		push(arr[i], st, 'a');
}

// Freeing the memory
void	destroy_stack(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
}

// Returns 1 (true) if capacity == size
int	is_full(t_stack *stack, char name)
{
	if (name == 'a')
		return (stack->a == stack->size_a);
	if (name == 'b')
		return (stack->b == stack->size_b);
}

// Returns 1 (true) if the stack is empty.
int	is_empty(t_stack *stack, char name)
{
	if (name == 'a')
		return (stack->size_a == 0);
	if (name == 'b')
		return (stack->size_b == 0);
}
