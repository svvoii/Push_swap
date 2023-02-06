/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/06 19:20:33 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Put the new item to the top of the stack (adds item to the end ofthe array)
int	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return (0);
	stack->collection[stack->size] = item;
	stack->size++;
	if (stack->s)
		printf("p%c\n", stack->s);
	return (1);
}

// Decreases the size ofthe array by 1
int	pop(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	stack->size--;
	*item = stack->collection[stack->size];
	return (1);
}

// Retrieves the top item from the stack (the last item of the array, size - 1)
/*
int	peek(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	*item = stack->collection[stack->size - 1];
	return (1);
}
*/

void	swap(int *a, int *b, char c)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("s%c\n", c);
}

// Moves the top item to bottom of stack (the last array item put at index 0)
void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->collection[stack->size - 1];
	i = stack->size - 2;
	while (i >= 0)
	{
		stack->collection[i + 1] = stack->collection[i];
		i--;
	}
	stack->collection[0] = tmp;
	printf("r%c\n", stack->s);
}

// The bottom stack value moved to the top (last array item appears at 0 index)
void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	tmp = stack->collection[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->collection[i] = stack->collection[i + 1];
		i++;
	}
	stack->collection[stack->size - 1] = tmp;
	printf("rr%c\n", stack->s);
}
