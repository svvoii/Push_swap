/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/21 16:37:43 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
//void	push_swap_to_b(t_stack *st);
void	next_index_to_push_b(t_stack *st, int *from_top, int *from_btm);
void	rotate_a_before_push_b(t_stack *st, int from_top, int from_btm);
void	equal_top_bott_placement(t_stack *st, int *item);

void	rotate_b_for_proper_insert(t_stack *st, int item);

void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);

void	indexing(t_stack *st)
{
	int	i;
	int	j;
	int	buf[st->size_a];

	i = -1;
	while (++i < st->size_a)
		buf[i] = st->a[i];
	merge_sort(buf, 0, i - 1);
	i = -1;
	while (++i < st->size_a)
	{
		j = -1;
		while (++j < st->size_a)
		{
			if (st->a[i] == buf[j])
			{
				st->a[i] = j;
				break ;
			}
		}
	}
}

int	ready_to_push_b(t_stack *st, int item)
{
	if (st->size_b > 1 && item > st->b[st->size_b - 1] && item < st->b[0])
		return (1);
	return (0);
}

int	is_max(t_stack *st, int item)
{
	int	i;

	i = -1;
	while (++i < st->size_b)
		if (item < st->b[i])
			return (0);
	return (1);
}

int is_min(t_stack *st, int item)
{
	int	i;

	i = -1;
	while (++i < st->size_b)
		if (item > st->b[i])
			return (0);
	return (1);
}

void	rotate_b_for_proper_insert(t_stack *st, int item)
{
	int	i;

	i = 0;
	if (st->size_b == 2)
		rotate_to_set_in_order_b(st, i);
	else if (ready_to_push_b(st, item))
		return ;
	else if (is_max(st, item) || is_min(st, item))
	{
		rotate_to_set_in_order_b(st, i);
		return ;
	}
	while (item < st->b[i] && i < st->size_b)
		i++;
	while (item > st->b[i] && i < st->size_b)
		i++;
	rotate_to_set_in_order_b(st, i);
}

void	next_index_to_push_b(t_stack *st, int *from_top, int *from_btm)
{
	int	n;
	int	top;
	int	btm;

	top = 0;
	btm = 0;
	n = (st->size_b / st->chunk) + 1;
	while (st->a[st->size_a - 1 - top] >= st->chunk * n)
		top++;
	while (st->a[btm] >= st->chunk * n)
		btm++;
	*from_top = top;
	*from_btm = btm;
}

void	rotate_a_before_push_b(t_stack *st, int from_top, int from_btm)
{
	if (from_top <= from_btm)
	{
		while (--from_top >= 0)
			rotate(st, 'a');
	}
	else
	{
		while (from_btm >= 0)
		{
			reverse_rotate(st, 'a');
			from_btm--;
		}
	}
}

void	equal_top_bott_placement(t_stack *st, int *item)
{
	int	n;
	int	from_top;
	int	from_btm;

	from_top = 0;
	from_btm = 0;
	n = (st->size_b / st->chunk) + 1;
	next_index_to_push_b(st, &from_top, &from_btm);
	//if (st->size_b < *item)
	if (*item < (st->chunk * n) - (st->chunk / 2))
	{
		if (from_top <= from_btm)
			rotate(st, 'r');
		else
			rotate(st, 'b');
	}
}

void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	top;
	int	btm;
	int	item;

	n = 1;
	//while (!is_empty(st, 'a'))
	while (st->size_a > 3)
	{
		next_index_to_push_b(st, &top, &btm);
		rotate_a_before_push_b(st, top, btm);

		pop(&item, st, 'a');
		push(item, st, 'b');

		equal_top_bott_placement(st, &item);

		n = (st->size_b / st->chunk) + 1;
		//if (st->size_b == (st->chunk * n))
		//	n++;
	}
	sort_three_nums(st);
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
			{
				rotate(st, 'b');
				st->count++;
			}
			else
			{
				reverse_rotate(st, 'b');
				st->count++;
			}
		}
		pop(&item, st, 'b');
		push(item, st, 'a');
	}
}

*/