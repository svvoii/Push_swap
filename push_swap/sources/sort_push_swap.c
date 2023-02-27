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
void	clac_r_in_a_for_each_b(t_stack *st, int *ra, int *rra);
void	prepare_for_min_spin(t_stack *st, int *ra_rra, int *rb_rrb);
void	direction_to_spin(t_stack *st, char name, int i);
void	min_a_vs_min_b(int *ra_rra, int *rb_rrb, int size, int *index);
int 	is_min(int *arr, int size, int item);
int		min_index(int *arr, int size);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);
void	spin(t_stack *st, int spin_a, int spin_b, int i, int *ra_rra);
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
	int	item;
	int	ra[st->capacity];

	while (!is_empty(st, 'b'))
	{
		clac_r_in_a_for_each_b(st, ra);
		
		prepare_for_min_spin(st, ra);
		/*
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);
		*/

		pop(&item, st, 'b');
		push(item, st, 'a');
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);
	}
	bring_min_to_top(st);
}

void	prepare_for_min_spin(t_stack *st, int *ra)
{
	int	i;
	int	spin_a;
	int	spin_b;
	int	min_i;
	int	max_i;

	min_i = 0;
	while (!is_min(ra, st->size_b, ra[min_i]))
		min_i++;
	max_i = 0;
	while (!is_max(ra, st->size_b, ra[max_i]))
		max_i++;
	spin_a = 0;
	spin_b = 0;
	min_a_vs_min_b(ra, st->size_b, &spin_a, &spin_b, &i);
	//spin_a = ra_rra[i];
	//spin_b = rb_rrb[i];

	printf("\tb[%d]:'%d' spin_a:'%d' .. spin_b:'%d'\n", i, st->b[st->size_b - 1 - i], spin_a, spin_b);

	spin(st, spin_a, spin_b, i, ra_rra);
}

void	min_a_vs_min_b(int *ra, int size, int *spin_a, int *spin_b, int *index)
{
	int	min_i;
	int	max_i;

	min_i = 0;
	while (!is_min(ra, size, ra[min_i]))
		min_i++;
	max_i = 0;
	while (!is_max(ra, size, ra[max_i]))
		max_i++;
	if (max_i < min_i) // rra (size_a - ra[max_i]) times to push B[max_i] to A
	{
		*spin_a = size - ra[max_i];
		*spin_b = max_i;
		// if (max_i <= size / 2) // rb (max_i) times to bring B[max_i] to B top
		// if (max_i > size / 2) // rrb (max_i) times to bring B[max_i] to B top
	}
	else if (min_i < max_i) // ra (ra[min_i]) times to push B[min_i]
	{
		*spin_a = ra[max_i];
		*spin_b = min_i;
		// if (min_i <= size / 2) // rb (min_i) times to bring B[min_i] to B top
		// if (min_i > size / 2) // rrb (min_i) times to bring B[min_i] to B top
	}
	printf(" i_a:'%d' i_b:'%d'", i_a, i_b);
}

void	spin(t_stack *st, int spin_a, int spin_b, int i, int *ra_rra)
{
	if ((ra_rra[i] > st->size_a / 2) && (i > st->size_b / 2)) // rra and rrb
	{
		while (spin_b > 0 && spin_a > 0)
		{
			direction_to_spin(st, 'r', -1);
			spin_b--;
			spin_a--;
		}
		while (spin_b-- > 0)
			direction_to_spin(st, 'b', -1);
		while (spin_a-- > 0)
			direction_to_spin(st, 'a', -1);
	}
	else if ((ra_rra[i] < st->size_a / 2) && (i < st->size_b / 2)) // ra and rb
	{
		while (spin_b > 0 && spin_a > 0)
		{
			direction_to_spin(st, 'r', 1);
			spin_b--;
			spin_a--;
		}
		while (spin_b-- > 0)
			direction_to_spin(st, 'b', 1);
		while (spin_a-- > 0)
			direction_to_spin(st, 'a', 1);
	}
	else if ((ra_rra[i] > st->size_a / 2) && (i < st->size_b / 2)) // rra and rb
	{
		while (spin_b-- > 0)
			direction_to_spin(st, 'b', 1);
		while (spin_a-- > 0)
			direction_to_spin(st, 'a', -1);
	}
	else if ((ra_rra[i] < st->size_a / 2) && (i > st->size_b / 2)) // ra and rrb
	{
		while (spin_b-- > 0)
			direction_to_spin(st, 'b', -1);
		while (spin_a-- > 0)
			direction_to_spin(st, 'a', 1);
	}
}

void	direction_to_spin(t_stack *st, char name, int i)
{
	if (i > 0)
		rotate(st, name);
	else if (i < 0)
		reverse_rotate(st, name);
}

void	clac_r_in_a_for_each_b(t_stack *st, int *ra)
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
		ra[i] = r;
	}
	printf("  ra[ ");
	i = -1;
	while (++i < st->size_b)
		printf("%d, ", ra[i]);
	printf("]\n");
	printf(" rra[ ");
	i = -1;
	while (++i < st->size_b)
		printf("%d, ", st->size_a - ra[i]);
	printf("]\n");
}

int is_max(int *arr, int size, int item)
{
	int	i;

	i = -1;
	while (++i < size)
		if (item < arr[i])
			return (0);
	return (1);
}

int is_min(int *arr, int size, int item)
{
	int	i;

	i = -1;
	while (++i < size)
		if (item > arr[i])
			return (0);
	return (1);
}

int	min_index(int *arr, int size)
{
	int	i;

	i = 0;
	while (!is_min(arr, size, arr[size - 1 - i]))
		i++;
	return (i);
}
/*
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
*/
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

void	bring_min_to_top(t_stack *st)
{
	int	i;

	i = min_index(st->a, st->size_a);
	if (i <= st->size_a / 2)
		while (i-- > 0)
			rotate(st, 'a');
	else
		while (i-- > 0)
			reverse_rotate(st, 'a');
}
