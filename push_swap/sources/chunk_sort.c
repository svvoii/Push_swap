/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/22 17:47:33 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
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

int	find_index(t_stack *st, char name, int item)
{
	int	i;
	int	top;

	i = 0;
	if (name == 'a')
	{
		top = st->size_a - 1;
		while (st->a[top - i] != item)
			i++;
	}
	else if (name == 'b')
	{
		top = st->size_b - 1;
		while (st->b[top - i] != item)
			i++;
	}
	return (i);
}

int	find_place_to_insert_b(t_stack *st, int item)
{
	int	i;
	int	top;
	int	max;

	i = 1;
	top = st->size_b - 1;
	if (item > st->b[top] && item < st->b[0])
		i = 0;
	else if (is_min(st, item) || is_max(st, item))
	{
		find_max(st, &max, i);
	}
	else
	{
		while (st->b[top - i] < item || st->b[top - 1 - i] > item)
			i++;
	}
	return (i);
}

// rotate_type_a_b
int	calc_rotations(t_stack *st)
{
	int	i;
	int	top;

	top = st->size_a - 1;
	i = case_rra_rrb(st, st->a[top]);
	while (top >= 0)
	{
		if (i > case_ra_rb(st, st->a[top]))
			i = case_ra_rb(st, st->a[top]);
		if (i > case_rra_rrb(st, st->a[top]))
			i = case_rra_rrb(st, st->a[top]);
		if (i > case_ra_rrb(st, st->a[top]))
			i = case_ra_rrb(st, st->a[top]);
		if (i > case_rra_rb(st, st->a[top]))
			i = case_rra_rb(st, st->a[top]);
		top--;
	}
	return (i);
}

// This function if not ready
void	calc_and_push_to_b(t_stack *st)
{
	int	item;

	while (st->size_b < 3)
	{
		pop(&item, st, 'a');
		push(item, st, 'b');
	}
	while (st->size_a > 3)
	{
		calc_next_push(st);
	}
}

void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	top;
	int	max;
	int	item;

	//n = (max / st->chunk);
	//while (!is_empty(st, 'a'))
	max = st->capacity - 1;
	n = (st->size_b / st->chunk) + 1;
	while (st->size_a > 3)
	{
		top = st->a[st->size_a - 1];
		//printf("\ta[%d]:'%d' s_b:'%d' s_a:'%d' n:'%d' chunk * n:'%d' \n", st->size_a - 1, top, st->size_b, st->size_a, n, st->chunk * n);
		if (top > st->chunk * n || top == max || top == max - 1 || top == max - 2)
			rotate(st, 'a');
		else if (top <= st->chunk * n)
		{
			pop(&item, st, 'a');
			push(item, st, 'b');
			top = st->a[st->size_a - 1];
			if (item < (st->chunk * n) - (st->chunk / 2))
			{
				if (top > st->chunk * n)
					rotate(st, 'r');
				else
					rotate(st, 'b');
			}
		}
		n = (st->size_b / st->chunk) + 1;
		//if (st->size_a <= (st->chunk * n))
		//	n--;
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
