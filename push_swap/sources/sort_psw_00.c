/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_psw_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 13:40:48 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
void	smart_push_back_to_a(t_stack *st);
void	clac_r_in_a_for_each_b(t_stack *st, int *ra, int *rb);
void	calc_rotations(int *ra, int *rb, int *rotations, int size);

/* sort into temp buf arr and use it to index unsorted stack */
void	indexing(t_stack *st)
{
	int	i;
	int	j;
	int	*buf;

	buf = (int *)malloc(sizeof(int) * st->capacity);
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
	free(buf);
}

/* pushing nums from a to b based on chunk devision */
void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	top;
	int	item;

	n = (st->size_b / st->chunk) + 1;
	while (st->size_a > 3 && !sorted(st))
	{
		top = st->a[st->size_a - 1];
		if (top > st->chunk * n || top >= st->capacity - 3)
			rotate(st, 'a', 1);
		else if (top <= st->chunk * n)
		{
			pop(&item, st, 'a');
			push(item, st, 'b', 1);
			top = st->a[st->size_a - 1];
			if (st->capacity > 20 && (item < (st->chunk * n) - (st->chunk / 2)))
			{
				if (top > st->chunk * n)
					rotate(st, 'r', 1);
				else
					rotate(st, 'b', 1);
			}
		}
		n = (st->size_b / st->chunk) + 1;
	}
}

/* following functions + those from psw_01-02 idetify least ammount of instr */
void	smart_push_back_to_a(t_stack *st)
{
	int	item;
	int	index;
	int	*ra;
	int	*rb;
	int	*rotations;

	ra = (int *)malloc(sizeof(int) * st->capacity);
	rb = (int *)malloc(sizeof(int) * st->capacity);
	rotations = (int *)malloc(sizeof(int) * st->capacity);
	sort_three_nums(st);
	while (st->size_b)
	{
		clac_r_in_a_for_each_b(st, ra, rb);
		calc_rotations(ra, rb, rotations, st->size_b);
		index = 0;
		while (!is_min(rotations, st->size_b, rotations[index]))
			index++;
		spin(st, ra, rb, index);
		pop(&item, st, 'b');
		push(item, st, 'a', 1);
	}
	bring_min_to_top(st);
	free(ra);
	free(rb);
	free(rotations);
}

void	clac_r_in_a_for_each_b(t_stack *st, int *ra, int *rb)
{
	int	i;
	int	r;
	int	item;

	i = -1;
	while (++i < st->size_b)
	{
		item = st->b[st->size_b - 1 - i];
		if (is_min(st->a, st->size_a, item))
			r = min_index(st->a, st->size_a);
		else if (item > st->a[st->size_a - 1])
			r = find_bigger(st, item);
		else if (item < st->a[st->size_a - 1])
			r = find_smaller(st, item);
		if (r <= st->size_a / 2)
			ra[i] = r;
		else
			ra[i] = (st->size_a - r) * -1;
		if (i <= st->size_b / 2)
			rb[i] = i;
		else
			rb[i] = (st->size_b - i) * -1;
	}
}

void	calc_rotations(int *ra, int *rb, int *rotations, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (ra[i] >= 0 && rb[i] >= 0)
		{
			if (ra[i] >= rb[i])
				rotations[i] = ra[i];
			else
				rotations[i] = rb[i];
		}
		else if (ra[i] < 0 && rb[i] < 0)
		{
			if (ra[i] <= rb[i])
				rotations[i] = abs(ra[i]);
			else
				rotations[i] = abs(rb[i]);
		}
		else
			rotations[i] = abs(ra[i]) + abs(rb[i]);
	}
}
