/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/25 11:16:1 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
void	smart_push_back_to_a(t_stack *st);
void	clac_r_in_a_for_each_b(t_stack *st, int *moves);
int 	is_min_in_a(t_stack *st, int item);
int		min_index(t_stack *st);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);
void	spin(t_stack *st, int spin_a, int spin_b, int direction);
void	bring_min_to_top(t_stack *st);

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

void	smart_push_back_to_a(t_stack *st)
{
	int	i;
	int	min;
	int	item;
	int	spin_a;
	int	spin_b;
	int	direction;
	int	moves[st->capacity];

	while (!is_empty(st, 'b'))
	{
		clac_r_in_a_for_each_b(st, moves);
		i = -1;
		min = moves[0];
		i = -1;
		while (++i < st->size_b)
		{
			if (moves[i] <= min)
			{
				min = moves[i];
				if (i <= moves[i] && i <= st->size_b / 2)
				{
					spin_a = moves[i];
					spin_b = i;
					direction = 1; // for rotate
				}
				else if (st->size_b - i < st->size_a - moves[i] && i > st->size_b / 2)
				{
					spin_a = st->size_a - moves[i];
					spin_b = st->size_b - i;
					direction = -1; // for reverse rotate
				}
			}
		}
		printf("\tspin_a:'%d' .. spin_b:'%d' >> '%d'\n", spin_a, spin_b, direction);
		//exit (0);
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);
		if (min > 0)
			spin(st, spin_a, spin_b, direction);
		pop(&item, st, 'b');
		push(item, st, 'a');
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);
	}
	bring_min_to_top(st);
}

void	clac_r_in_a_for_each_b(t_stack *st, int *moves)
{
	int	i;
	int	r;
	int	item;

	i = -1;
	while (++i < st->size_b)
	{
		item = st->b[st->size_b - 1 - i];
		if (is_min_in_a(st, item))
		{
			r = min_index(st);
		}
		else if (item > st->a[st->size_a - 1])
		{
			r = find_bigger(st, item);
		}
		else if (item < st->a[st->size_a - 1])
		{
			r = find_smaller(st, item);
		}
		moves[i] = r;
	}
}

int is_min_in_a(t_stack *st, int item)
{
	int	i;

	i = -1;
	while (++i < st->size_a)
		if (item > st->a[i])
			return (0);
	return (1);
}

int	min_index(t_stack *st)
{
	int	i;

	i = 0;
	while (!is_min_in_a(st, st->a[st->size_a - 1 - i]))
		i++;
	return (i);
}

int	find_bigger(t_stack *st, int item)
{
	int	i;

	i = 0;
	while (item > st->a[st->size_a - 1 - i])
		i++;
	return (i);
}

int	find_smaller(t_stack *st, int item)
{
	int	i;

	if (item < st->a[st->size_a - 1] && item > st->a[0])
		return (0);
	i = 0;
	while (item < st->a[st->size_a - 1 - i])
		i++;
	return (i);
}

void	spin(t_stack *st, int spin_a, int spin_b, int direction)
{
	if (direction > 0)
	{
		while (spin_b-- > 0)
			rotate(st, 'r');
		while (spin_a-- > 0)
			rotate(st, 'a');
	}
	else if (direction < 0)
	{
		while (spin_b-- > 0)
			reverse_rotate(st, 'r');
		while (spin_a-- > 0)
			reverse_rotate(st, 'a');
	}
}

void	bring_min_to_top(t_stack *st)
{
	int	i;

	i = min_index(st);
	if (i <= st->size_a / 2)
		while (i-- > 0)
			rotate(st, 'a');
	else
		while (i-- > 0)
			reverse_rotate(st, 'a');
}
