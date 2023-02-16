/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/16 18:29:52 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
//void	push_swap_to_b(t_stack *st);
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
	printf("\ta[%d]:'%d' .. a[%d]:'%d' .. chunk:'%d'\n", top - tmp1, st->a[top - tmp1], tmp2, st->a[tmp2], chunk);
	if (tmp1 <= tmp2)
	{
		while (--tmp1 >= 0)
		{
			rotate(st, 'a');
			printf("\t\tr: tmp1:'%d' top:'%d'\n", tmp1, st->a[top]);
		}
	}
	else
	{
		while (tmp2 >= 0)
		{
			reverse_rotate(st, 'a');
			printf("\t\trr: tmp2:'%d' top:'%d'\n", tmp2, st->a[top]);
			tmp2--;
		}
	}
}

void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	chunk;
	int	item;

	print_array(st->a, st->size_a);
	n = 1;
	chunk = (st->size_a / 5);
	while (!is_empty(st, 'a'))
	{
		return_index_to_push(st, (chunk * n));
		pop(&item, st, 'a');
		push(item, st, 'b');
		printf("item:'%d' .. b[%d]:'%d'\n", item, st->size_b - 1, st->b[st->size_b - 1]);
		if (st->size_b == (chunk * n))
		{
			print_array(st->a, st->size_a);
			printf("chunk:'%d' size_b:'%d' size_a:'%d'\n", chunk * n, st->size_b, st->size_a);
			print_array(st->b, st->size_b);
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
