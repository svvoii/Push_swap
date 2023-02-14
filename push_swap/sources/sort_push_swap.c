/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/14 16:52:23 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap_to_b(t_stack *st);
void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);

void	push_swap_to_b(t_stack *st)
{
	int	i;
	int	n;
	int	top;
	int	item;
	int	chunk;

	i = 1;
	n = 1;
	chunk = ((st->size_a - 1) / 10) + 10;
	printf("chunk:'%d'\tsize_b:'%d'\tsize_a:'%d'\n", chunk, st->size_b, st->size_a);
	return ;
	while (!is_empty(st, 'a'))
	{
		top = st->size_a - 1;
		printf("a[%d]:'%d'\n", top, st->a[top]);
		if (st->a[top] < chunk * n)
		{
			pop(&item, st, 'a');
			push(item, st, 'b');
			top = st->size_b - 1;
			if (top && st->b[top] < (chunk * n) - (chunk / 2))
				rotate(st->b, st->size_b, 'b');
			i++;
		}
		else
			while (st->a[top] >= chunk * n)
				rotate(st->a, st->size_a, 'a');
		if (i == chunk * n)
			n++;
	}
}

void	find_max(t_stack *st, int *max, int *index)
{
	int	i;

	i = -1;
	*max = st->b[st->size_b - 1];
	while (++i < st->size_b)
	{
		if (st->b[i] > *max)
		{
			*max = st->b[i];
			*index = i;
		}
	}
}

void	push_swap_back_to_a(t_stack *st)
{
	int	max;
	int	top;
	int	index;
	int	item;

	while (!is_empty(st, 'b'))
	{
		find_max(st, &max, &index);
		top = st->size_b - 1;
		while (st->b[top] != max)
		{
			if (index >= top / 2)
				rotate(st->b, st->size_b, 'b');
			else
				reverse_rotate(st->b, st->size_b, 'b');
		}
		pop(&item, st, 'b');
		push(item, st, 'a');
	}
}
