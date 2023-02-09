/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:59:30 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/0 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns 1 if stack is sorted
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

// Conditions to sort a when there is only 3 values in it
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

// Rotates b to put nums in descending order based on situation
void	rotate_to_set_in_order(t_stack *st, int n)
{
	int	i;

	i = n;
	if (i == 0)
	{
		while (++i < st->size)
			if (st->collection[i - 1] > st->collection[i])
				break ;
		if (i == st->size)
			return ;
	}
	if (i <= st->size / 2)
		while (--i >= 0)
			reverse_rotate(st);
	else
		while (st->size - ++i >= 0)
			rotate(st);
}

// Aux f() which identifies the index in b where to insert
void	search_index_to_insert(t_stack *b, int value)
{
	int	i;

	i = 0;
	if (b->size < 2)
		return ;
	rotate_to_set_in_order(b, i);
	if (value > b->collection[0] && value < b->collection[b->size - 1])
	{
		i = 0;
		while (++i < b->size)
			if (value > b->collection[i - 1] && value < b->collection[i])
				break ;
	}
	if (!i)
		return ;
	rotate_to_set_in_order(b, i);
}

void	find_lowest_and_swap_or_rr(t_stack *a)
{
	if (a->collection[a->size - 2] < a->collection[a->size - 1] && a->collection[a->size - 2] < a->collection[0])
		swap(&a->collection[a->size - 1], &a->collection[a->size - 2], a->s);
	else if (a->collection[0] < a->collection[a->size - 1] && a->collection[0] < a->collection[a->size - 2])
		reverse_rotate(a);
}

// Main sorting f() which calls different actions while a is not sorted
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
			search_index_to_insert(b, value);
			push(b, value);
		}
	}
	rotate_to_set_in_order(b, 0);
	while (!is_empty(b))
	{
		pop(b, &value);
		push(a, value);
		find_lowest_and_swap_or_rr(a);
	}
}
