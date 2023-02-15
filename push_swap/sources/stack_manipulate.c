/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/15 14:57:02 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		push(int item, t_stack *st, char name);
int		pop(int *item, t_stack *stack, char name);
void	swap(t_stack *st, int a, int b, char name);
void	rotate(t_stack *st, char name);
void	reverse_rotate(t_stack *st, char name);

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
	st->count++;
	//printf("p%c\n", name);
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

void	swap(t_stack *st, int a, int b, char name)
{
	int	tmp;

	tmp = st->a[a];
	st->a[a] = st->a[b];
	st->a[b] = tmp;
	if (name == 'a' || name == 'b')
		st->count++;
		//printf("s%c\n", name);
}

// Moves the top item to bottom of stack (the last array item put at index 0)
void	rotate(t_stack *st, char name)
{
	int	tmp;
	int	i;

	if (name == 'a')
	{
		tmp = st->a[st->size_a - 1];
		i = st->size_a - 1;
		while (--i >= 0)
			st->a[i + 1] = st->a[i];
		st->a[0] = tmp;
	}
	else if (name == 'b')
	{
		tmp = st->b[st->size_b - 1];
		i = st->size_b - 1;
		while (--i >= 0)
			st->b[i + 1] = st->b[i];
		st->b[0] = tmp;
	}
	if (name == 'a' || name == 'b')
		st->count++;
		//printf("r%c\n", name);
}

// The bottom stack value moved to the top (last array item appears at 0 index)
void	reverse_rotate(t_stack *st, char name)
{
	int	i;
	int	tmp;

	if (name == 'a')
	{
		tmp = st->a[0];
		i = -1;
		while (++i < st->size_a - 1)
			st->a[i] = st->a[i + 1];
		st->a[st->size_a - 1] = tmp;
	}
	if (name == 'b')
	{
		tmp = st->b[0];
		i = -1;
		while (++i < st->size_b - 1)
			st->b[i] = st->b[i + 1];
		st->b[st->size_b - 1] = tmp;
	}
	if (name == 'a' || name == 'b')
		st->count++;
		//printf("rr%c\n", name);
}
