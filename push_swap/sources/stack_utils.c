/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/13 13:32:31 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Put the new item to the top of the stack (adds item to the end ofthe array)
int	push(int item, t_stack *stack, char name)
{
	if (is_full(st, name))
		return (0);
	if (name == 'a')
	{
		stack->a[stack->size_a] = item;
		stack->size_a++;
	}
	else if (name == 'b')
	{
		stack->b[stack->size_b] = item;
		stack->size_b++;
	}
	printf("p%c\n", name);
	return (1);
}

// Decreases the size ofthe array by 1
int	pop(t_stack *stack, char name, int *item)
{
	if (is_empty(stack, name))
		return (0);
	if (name == 'a')
	{
		stack->size_a--;
		*item = stack->a[stack->size_a];
	}
	else if (name == 'b')
	{
		stack->size_b--;
		*item = stack->b[stack->size_b];
	}
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

void	swap(int *a, int *b, char name)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("s%c\n", name);
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
