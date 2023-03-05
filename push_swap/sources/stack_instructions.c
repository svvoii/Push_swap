/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/05 10:42:53 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(int item, t_stack *st, char name, int print);
void	pop(int *item, t_stack *stack, char name);
void	swap(t_stack *st, char name, int print);
void	rotate(t_stack *st, char name, int print);
void	reverse_rotate(t_stack *st, char name, int print);

// Put the new item to the top of the stack (adds item to the end ofthe array)
void	push(int item, t_stack *st, char name, int print)
{
	if ((name == 'a' && st->size_a == st->capacity)
		|| (name == 'b' && st->size_b == st->capacity))
		return;
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
	if (print)
		printf("p%c\n", name);
}

/* Decreases the size ofthe array by 1 */
void	pop(int *item, t_stack *st, char name)
{
	if (name == 'a')
	{
		if (!st->size_a)
			return;
		st->size_a--;
		*item = st->a[st->size_a];
	}
	else if (name == 'b')
	{
		if (!st->size_a)
			return;
		st->size_b--;
		*item = st->b[st->size_b];
	}
}

/* swap two top values of stack a or/and b */
void	swap(t_stack *st, char name, int print)
{
	int	tmp;
	int	top;

	if (name == 'a' || name == 'r')
	{
		top = st->size_a - 1;
		tmp = st->a[top];
		st->a[top] = st->a[top - 1];
		st->a[top - 1] = tmp;
	}
	if (name == 'b' || name == 'r')
	{
		top = st->size_b - 1;
		tmp = st->b[top];
		st->b[top] = st->b[top - 1];
		st->b[top - 1] = tmp;
	}
	if (print)
		printf("s%c\n", name);
}

/* Moves the top item to bottom of stack (the last array item put at index 0) */
void	rotate(t_stack *st, char name, int print)
{
	int	tmp;
	int	i;

	if (name == 'a' || name == 'r')
	{
		tmp = st->a[st->size_a - 1];
		i = st->size_a - 1;
		while (--i >= 0)
			st->a[i + 1] = st->a[i];
		st->a[0] = tmp;
	}
	if (name == 'b' || name == 'r')
	{
		tmp = st->b[st->size_b - 1];
		i = st->size_b - 1;
		while (--i >= 0)
			st->b[i + 1] = st->b[i];
		st->b[0] = tmp;
	}
	if (print)
		printf("r%c\n", name);
}

/* The bottom stack value moved to the top (last array item appears at 0 index) */
void	reverse_rotate(t_stack *st, char name, int print)
{
	int	i;
	int	tmp;

	if (name == 'a' || name == 'r')
	{
		tmp = st->a[0];
		i = -1;
		while (++i < st->size_a - 1)
			st->a[i] = st->a[i + 1];
		st->a[st->size_a - 1] = tmp;
	}
	if (name == 'b' || name == 'r')
	{
		tmp = st->b[0];
		i = -1;
		while (++i < st->size_b - 1)
			st->b[i] = st->b[i + 1];
		st->b[st->size_b - 1] = tmp;
	}
	if (print)
		printf("rr%c\n", name);
}

/* Returns 1 (true) if the stack is empty.
int	is_empty(t_stack *stack, char name)
{
	if (name == 'a')
		return (stack->size_a == 0);
	else if (name == 'b')
		return (stack->size_b == 0);
	return (0);
}
*/