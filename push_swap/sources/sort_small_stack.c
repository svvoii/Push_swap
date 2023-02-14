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

// Main sorting f() which calls different actions while a is not sorted
void	sort_small_stack(t_stack *st)
{
	int	item;

	while (!sorted(st))
	{
		if (st->size_a == 3)
			sort_three_nums(st);
		else
		{
			find_lowest_and_swap_or_rr(st->a, st->size_a);
			pop(&item, st, 'a');
			search_index_to_insert(st->b, st->size_b, item);
			push(item, st, 'b');
		}
	}
	rotate_to_set_in_order_b(st->b, st->size_b, 0);
	while (!is_empty(st, 'b'))
	{
		pop(&item, st, 'b');
		push(item, st, 'a');
		find_lowest_and_swap_or_rr(st->a, st->size_a);
	}
}

// Conditions to sort a when there is only 3 values in it
void	sort_three_nums(t_stack *st)
{
	if (st->size_a != 3)
		return ;
	while (!sorted(st))
	{
		if (st->a[0] > st->a[1])
		{
			if (st->a[1] < st->a[2] && st->a[2] < st->a[0])
				swap(&st->a[1], &st->a[2], 'a');
			else
				rotate(st->a, st->size_a, 'a');
		}
		else if (st->a[0] < st->a[1])
		{
			if (st->a[0] < st->a[2] && st->a[1] > st->a[2]) 
				reverse_rotate(st->a, st->size_a, 'a');
			else
				swap(&st->a[1], &st->a[2], 'a');
		}
	}
}

void	find_lowest_and_swap_or_rr(int *a, int size)
{
	if (a[size - 2] < a[size - 1] && a[size - 2] < a[0])
		swap(&a[size - 1], &a[size - 2], 'a');
	else if (a[0] < a[size - 1] && a[0] < a[size - 2])
		reverse_rotate(a, size, 'a');
}

// Aux f() which identifies the index in b where to insert
void	search_index_to_insert(int *b, int size, int value)
{
	int	i;

	i = 0;
	if (size < 2)
		return ;
	rotate_to_set_in_order_b(b, size, i);
	if (value > b[0] && value < b[size - 1])
	{
		i = 0;
		while (++i < size)
			if (value > b[i - 1] && value < b[i])
				break ;
	}
	if (!i)
		return ;
	rotate_to_set_in_order_b(b, size, i);
}

// Rotates b to put nums in descending order based on situation
void	rotate_to_set_in_order_b(int *b, int size, int n)
{
	int	i;

	i = n;
	if (i == 0)
	{
		while (++i < size)
			if (b[i - 1] > b[i])
				break ;
		if (i == size)
			return ;
	}
	if (i <= size / 2)
		while (--i >= 0)
			reverse_rotate(b, size, 'b');
	else
		while (size - ++i >= 0)
			rotate(b, size, 'b');
}
