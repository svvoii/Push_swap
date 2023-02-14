/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/14 13:52:46 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Put the new item to the top of the stack (adds item to the end ofthe array)
int	push(int item, t_stack *st, char name)
{
	if ((name == 'a' && st->size_a == st->capacity)
		|| (name == 'b' && st->size_b == st->capacity))
		return (0);
	if (name == 'a')
	{
		st->a[st->size_a] = item;
		st->size_a++;
	}
	else if (name == 'b')
	{
		st->b[st->size_b] = item;
		st->size_b++;
	}
	printf("p%c\n", name);
	return (1);
}

// Decreases the size ofthe array by 1
int	pop(int *item, t_stack *stack, char name)
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

void	swap(int *a, int *b, char name)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	if (name == 'a' || name == 'b')
		printf("s%c\n", name);
}

// Moves the top item to bottom of stack (the last array item put at index 0)
void	rotate(int *stack, int size, char name)
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
	if (name == 'a' || name == 'b')
		printf("r%c\n", name);
}

// The bottom stack value moved to the top (last array item appears at 0 index)
void	reverse_rotate(int *stack, int size, char name)
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
	if (name == 'a' || name == 'b')
		printf("rr%c\n", name);
}
