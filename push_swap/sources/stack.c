/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/04 17:25:01 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Allocating memory for a structure and for int arr of given capacity
t_stack	*create_stack(int c, int capacity)
{
	t_stack	*stack;

	if (capacity <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->collection = malloc(sizeof(int) * capacity);
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	stack->s = c;
	return (stack);
}

// Filling in the stack from int arr. First element on top/last in arr
void	fill_in_stack(t_stack *a, int *arr)
{
	int	i;

	i = a->capacity;
	while (--i >= 0)
		push(a, arr[i]);
}

// Freeing the memory
void	destroy_stack(t_stack *stack)
{
	if (stack->collection)
		free(stack->collection);
	if (stack)
		free(stack);
}

// Returns 1 (true) if capacity == size
int	is_full(t_stack *stack)
{
	return (stack->capacity == stack->size);
}

// Returns 1 (true) if the stack is empty.
int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
