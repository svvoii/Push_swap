/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/24 13:01:36 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack *st);
void	push_chunks_to_b(t_stack *st);
void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);

int		is_max(t_stack *st, int item);
int 	is_min(t_stack *st, char name, int item);
int		find_index(t_stack *st, char name, int item);
int		find_place_to_insert_b(t_stack *st, int item);
int		calc_rotations(t_stack *st);
void	calc_and_push_to_b(t_stack *st);

void	min_index(t_stack *st, char name, int *i);
int		condition_to_insert(t_stack *st, int item);
void	smart_push_back_to_a(t_stack *st);

int	is_max(t_stack *st, int item)
{
	int	i;

	i = -1;
	while (++i < st->size_b)
		if (item < st->b[i])
			return (0);
	return (1);
}

int is_min(t_stack *st, char name, int item)
{
	int	i;

	i = -1;
	if (name == 'a')
	{
		while (++i < st->size_a)
			if (item > st->a[i])
				return (0);
	}
	else if (name == 'b')
	{
		while (++i < st->size_b)
			if (item > st->b[i])
				return (0);
	}
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
	else if (is_min(st, 'b', item) || is_max(st, item))
	{
		find_max(st, &max, &i);
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
	printf("\tclac_rotate a[%d]:'%d'  i:'%d'\n", top, st->a[top], i);
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
		printf("\tclac_rotate a[%d]:'%d'  i:'%d'\n", top, st->a[top], i);
		top--;
	}
	return (i);
}

// This function if not ready
// sort_b_till_3
void	calc_and_push_to_b(t_stack *st)
{
	int	i;
	int	top;
	int	item;

	while (st->size_b < 2)
	{
		pop(&item, st, 'a');
		push(item, st, 'b');
	}
	//while (st->size_a > 3)
	while (!is_empty(st, 'a'))
	{
		i = calc_rotations(st);
		top = st->size_a - 1;
		printf("i:'%d' .. \n", i);
		while (i >= 0)
		{
			printf("\ta:\t");
			print_array(st->a, st->size_a);
			printf("\tb:\t");
			print_array(st->b, st->size_b);
			if (i == case_ra_rb(st, st->a[top]))
			{
				i = ra_rb(st, st->a[top]);
			}
			else if (i == case_rra_rrb(st, st->a[top]))
				i = rra_rrb(st, st->a[top]);
			else if (i == case_ra_rrb(st, st->a[top]))
				i = ra_rrb(st, st->a[top]);
			else if (i == case_rra_rb(st, st->a[top]))
				i = rra_rb(st, st->a[top]);
			else
				top--;
		}
		pop(&item, st, 'a');
		push(item, st, 'b');
		printf("item:'%d'\n", item);
		printf("\ta:\t");
		print_array(st->a, st->size_a);
		printf("\tb:\t");
		print_array(st->b, st->size_b);
	}
	//sort_three_nums(st);
}

// Simple working algo (500 nums above around 5500)
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

void	calc_moves_to_push_from_b(t_stack *st, int *moves)
{
	int	i;
	int	j;
	int	item;

	item = st->size_b;
	while (--item >= 0)
	{
		i = 0;
		while (st->b[item] > st->a[st->size_a - 1 - i])
		{
			i++;
		}
		moves[item] = i;
	}
}

void	min_index(t_stack *st, char name, int *i)
{
	int	top;

	*i = 0;
	if (name == 'a')
	{
		top = st->size_a - 1;
		while (!is_min(st, 'a', st->a[top - *i]))
			*i += 1;
	}
	else if (name == 'b')
	{
		top = st->size_b - 1;
		while (!is_min(st, 'b', st->b[top - *i]))
			*i += 1;
	}
	//return (i);
}

int	condition_to_insert(t_stack *st, int item)
{
	if (item < st->a[st->size_a - 1] && item > st->a[0])
		return (1);
	return (0);
}

void	bring_min_to_top(t_stack *st)
{
	int	i;

	min_index(st, 'a', &i);
	if (i <= st->size_a / 2)
	{
		while (i--)
			rotate(st, 'a');
	}
	else
	{
		i = st->size_a - i;
		while (i--)
			reverse_rotate(st, 'a');
	}
}

void	smart_push_back_to_a(t_stack *st)
{
	int	i;
	int	top_a;
	int	top_b;
	int	item;

	//printf("a: '");
	//print_array(st->a, st->size_a);
	while (!is_empty(st, 'b'))
	{
		top_a = st->size_a - 1;
		top_b = st->size_b - 1;
		// ITEM is MIN in A
		if (is_min(st, 'a', st->b[top_b]))
		{
			//printf("TOP B is MIN in A\n");
			bring_min_to_top(st);
		}
		else if (st->b[top_b] > st->a[top_a])
		{
			//printf("TOP B > TOP A\n");
			while (!condition_to_insert(st, st->b[top_b]))
				rotate(st, 'a');
/*
			i = 0; // the amount of rotations for a
			while (st->b[top_b] > st->a[top_a - i])
				i++;
			//printf("\ti:'%d'\n", i);
			while (i-- > 0)
				rotate(st, 'a');
*/
		}
		else if (st->b[top_b] < st->a[top_a])
		{
			//printf("TOP B < TOP A\n");
			//print_array(st->a, st->size_a);
			while (!condition_to_insert(st, st->b[top_b]))
				reverse_rotate(st, 'a');
		}
		pop(&item, st, 'b');
		push(item, st, 'a');
		/*
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);
		*/
	}
	bring_min_to_top(st);
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
