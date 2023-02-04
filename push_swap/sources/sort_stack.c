/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:59:30 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/04 17:23:22 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted(t_stack *st)
{
	int	i;

	if (st->size == 0)
		return (0);
	i = st->size;
	while (--i > 0)
	{
		if (st->collection[i] > st->collection[i - 1])
			return (0);
	}
	return (1);
}

void	sort_three_nums(t_stack *st)
{
	int	*a;

	if (st->size != 3)
		return ;
	a = st->collection;
	while (!sorted(st))
	{
		if (a[0] > a[1])
		{
			if (a[1] < a[2] && a[2] < a[0])
				swap(&a[1], &a[2], st->s);
			else
				rotate(st);
		}
		else if (a[0] < a[1])
		{
			if (a[0] < a[2] && a[1] > a[2]) 
				reverse_rotate(st);
			else
				swap(&a[1], &a[2], st->s);
		}
	}
}

void	find_lowest_and_swap_or_rr(t_stack *st)
{
	if (st->collection[st->size - 2] < st->collection[st->size - 1] && st->collection[st->size - 2] < st->collection[0])
		swap(&st->collection[st->size - 1], &st->collection[st->size - 2], st->s);
	else if (st->collection[0] < st->collection[st->size - 1] && st->collection[0] < st->collection[st->size - 2])
		reverse_rotate(st);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	value;

	while (!sorted(a))
	{
		if (a->size == 3)
			sort_three_nums(a);
		else
		{
			find_lowest_and_swap_or_rr(a);
			pop(a, &value);
			// rotate b for proper spot to insert value
			push(b, value);
		}
	}
	printf("b:");
	print_array(b->collection, b->size);
	while (!is_empty(b))
	{
		find_lowest_and_swap_or_rr(b);
		pop(b, &value);
		push(a, value);
	}
}
