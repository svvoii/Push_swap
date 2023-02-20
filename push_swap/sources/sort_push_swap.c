/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/20 18:29:21 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
//void	push_swap_to_b(t_stack *st);
void	next_index_to_push(t_stack *st, int *tmp1, int *tmp2);
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

void	return_index_to_push(t_stack *st, int chunk)
{
	int	top;
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	top = st->size_a - 1;
	while (st->a[top - tmp1] >= chunk)
		tmp1++;
	while (st->a[tmp2] >= chunk)
		tmp2++;
	//printf("\ta[%d]:'%d' .. a[%d]:'%d' .. chunk:'%d'\n", top - tmp1, st->a[top - tmp1], tmp2, st->a[tmp2], chunk);
	if (tmp1 <= tmp2)
	{
		while (--tmp1 >= 0)
		{
			rotate(st, 'a');
			//printf("\t\tr: tmp1:'%d' top:'%d'\n", tmp1, st->a[top]);
		}
	}
	else
	{
		while (tmp2 >= 0)
		{
			reverse_rotate(st, 'a');
			//printf("\t\trr: tmp2:'%d' top:'%d'\n", tmp2, st->a[top]);
			tmp2--;
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

/*
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

*/
void	next_index_to_push(t_stack *st, int *tmp1, int *tmp2)
{
	int	top;

	*tmp1 = 0;
	*tmp2 = 0;
	top = st->size_a - 1;
	while (st->a[top - *tmp1] >= st->chunk)
		*tmp1 += 1;
	while (st->a[*tmp2] >= st->chunk)
		*tmp2 += 1;
}

void	equal_top_bott_placement(t_stack *st, int *item, int chunk_total)
{
	int	top;
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	top = st->size_a - 1;
	while (st->a[top - tmp1] >= st->chunk)
		tmp1++;
	while (st->a[tmp2] >= st->chunk)
		tmp2++;
	//if (st->size_b < *item)
	if (*item < chunk_total - (st->chunk / 2))
	{
		if (tmp1 <= tmp2)
			rotate(st, 'r');
		else
			rotate(st, 'b');
	}
}

void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	item;

	n = 1;
	if (st->size_a < 101)
		st->chunk = (st->size_a / 5);
	if (st->size_a > 400)
		st->chunk = (st->size_a / 9);
	while (!is_empty(st, 'a'))
	{
		return_index_to_push(st, (st->chunk * n));
		pop(&item, st, 'a');
		//rotate_b_for_proper_insert(st, item);
		push(item, st, 'b');
		equal_top_bott_placement(st, &item, st->chunk * n);

		if (st->size_b == (st->chunk * n))
		{
			n++;
		}
	}
}
/*
void	push_swap_to_b(t_stack *st)
{
	int	i;
	int	n;
	int	top;
	int	item;
	int	chunk;

	i = 1;
	n = 1;
	//chunk = ((st->size_a) / 10) + 10;
	chunk = ((st->size_a) / 5);
	printf("chunk:'%d'\tsize_b:'%d'\tsize_a:'%d'\n", chunk, st->size_b, st->size_a);
	while (!is_empty(st, 'a'))
	{
		top = st->size_a - 1;
		if (st->a[top] < chunk * n)
		{
			pop(&item, st, 'a');
			push(item, st, 'b');
			top = st->size_b - 1;
			if (top < (chunk * n) - (chunk / 2))
			{
				rotate(st, 'b');
			}
			i++;
		}
		else
		{
			//printf("else: rotate a\n");
			while (st->a[top] >= chunk * n)
			{
				rotate(st, 'a');
			}
		}
		if (i == chunk * n)
		{
			printf("chunk:'%d'\tsize_b:'%d'\tsize_a:'%d'\t", chunk, st->size_b, st->size_a);
			printf("\ti:'%d'\n", i);
			n++;
		}
	}
}
*/
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
