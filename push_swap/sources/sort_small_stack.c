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

void	sort_small_stack(t_stack *st);
void	sort_three_nums(t_stack *st);
void	find_lowest_and_swap_or_rr(t_stack *st, char name, int i);
void	search_index_to_insert_b(t_stack *st, int value);
void	rotate_to_set_in_order_b(t_stack *st, int n);

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
			find_lowest_and_swap_or_rr(st, 'a', st->size_a);
			pop(&item, st, 'a');
			search_index_to_insert_b(st, item);
			push(item, st, 'b');
		}
	}
	rotate_to_set_in_order_b(st, 0);
	while (!is_empty(st, 'b'))
	{
		pop(&item, st, 'b');
		push(item, st, 'a');
		find_lowest_and_swap_or_rr(st, 'a', st->size_a);
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
				swap(st, 1, 2, 'a');
			else
				rotate(st, 'a');
		}
		else if (st->a[0] < st->a[1])
		{
			if (st->a[0] < st->a[2] && st->a[1] > st->a[2]) 
				reverse_rotate(st, 'a');
			else
				swap(st, 1, 2, 'a');
		}
	}
}

void	find_lowest_and_swap_or_rr(t_stack *st, char name, int i)
{
	if (st->a[i - 2] < st->a[i - 1] && st->a[i - 2] < st->a[0])
		swap(st, i - 1, i - 2, name);
	else if (st->a[0] < st->a[i - 1] && st->a[0] < st->a[i - 2])
		reverse_rotate(st, name);
}

// Aux f() which identifies the index in b where to insert
void	search_index_to_insert_b(t_stack *st, int value)
{
	int	i;

	i = 0;
	if (st->size_b < 2)
		return ;
	rotate_to_set_in_order_b(st, i);
	if (value > st->b[0] && value < st->b[st->size_b - 1])
	{
		i = 0;
		while (++i < st->size_b)
			if (value > st->b[i - 1] && value < st->b[i])
				break ;
	}
	if (!i)
		return ;
	rotate_to_set_in_order_b(st, i);
}

// Rotates b to put nums in descending order based on situation
void	rotate_to_set_in_order_b(t_stack *st, int i)
{
	int	tmp1;
	int	tmp2;

	next_index_to_push(st, &tmp1, &tmp2);
	if (i == 0)
	{
		while (++i < st->size_b)
			if (st->b[i - 1] > st->b[i])
				break ;
		if (i == st->size_b)
			return ;
	}
	if (i <= st->size_b / 2)
		while (--i >= 0)
		{
			if (tmp1 > tmp2 && tmp2--)
				reverse_rotate(st, 'r');
			else
				reverse_rotate(st, 'b');
		}
	else
		while (st->size_b - ++i >= 0)
		{
			if (tmp1 <= tmp2 && --tmp1)
				rotate(st, 'r');
			else
				rotate(st, 'b');
		}
}
