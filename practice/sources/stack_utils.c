/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/11 11:04:59 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p_swap.h"

// Put the new item to the top of the stack (adds item to the end ofthe array)
int	push(t_stack *stack, char s, int item)
{
	if (is_full(stack, s))
		return (0);
	if (s == 'a')
	{
		stack->a[stack->size_a] = item;
		stack->size_a++;
	}
	else if (s == 'b')
	{
		stack->b[stack->size_b] = item;
		stack->size_b++;
	}
	printf("p%c\n", s);
	return (1);
}

// Decreases the size ofthe array by 1
int	pop(t_stack *stack, char s, int *item)
{
	if (is_empty(stack, s))
		return (0);
	if (s == 'a')
	{
		stack->size_a--;
		*item = stack->a[stack->size_a];
	}
	else if (s == 'b')
	{
		stack->size_b--;
		*item = stack->b[stack->size_b];
	}
	return (1);
}

void	swap(int *a, int *b, char s)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	if (s == 'a' || s == 'b')
		printf("s%c\n", s);
}

// Moves the top item to bottom of stack (the last array item put at index 0)
void	rotate(int *stack, int size, char s)
{
	int	tmp;
	int	i;

	tmp = stack[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = tmp;
	if (s == 'a' || s == 'b')
		printf("r%c\n", s);
}

// The bottom stack value moved to the top (last array item appears at 0 index)
void	reverse_rotate(int *stack, int size, char s)
{
	int	i;
	int	tmp;

	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
	if (s == 'a' || s == 'b')
		printf("rr%c\n", s);
}

// Returns 1 (true) if capacity == size
int	is_full(t_stack *stack, char s)
{
	if (s == 'a')
		return (stack->capacity == stack->size_a);
	else if (s == 'b')
		return (stack->capacity == stack->size_b);
}

// Returns 1 (true) if the stack is empty.
int	is_empty(t_stack *stack, char s)
{
	if (s == 'a')
		return (stack->size_a == 0);
	if (s == 'b')
		return (stack->size_b == 0);
}
