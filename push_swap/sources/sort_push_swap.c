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
void	clac_r_in_a_for_each_b(t_stack *st, int *ra, int *rb);
void	calc_rotations(int *ra, int *rb, int size, int *index);
int		abs(int n);
void	spin(t_stack *st, int *ra, int *rb, int i);
void	rr_ra_rb(t_stack *st, int a, int b);
void	rrr_rra_rrb(t_stack *st, int a, int b);
int		min_index(int *arr, int size);
int 	is_min(int *arr, int size, int item);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);
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

/*
void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	top;
	int	item;

	n = (st->size_b / st->chunk) + 1;
	while (st->size_a > 3)
	{
		top = st->a[st->size_a - 1];
		//printf("top:'%d' chunk:'%d' size:'%d'\n", top, (st->capacity - (st->chunk * n)), st->capacity);
		if (top < (st->capacity - (st->chunk * n)) || top >= st->capacity - 3)
			rotate(st, 'a');
		else
		{
			pop(&item, st, 'a');
			push(item, st, 'b');
			top = st->a[st->size_a - 1];
			if (item < (st->capacity - (st->chunk * n)) + (st->chunk / 2))
			{
				rotate(st, 'r');
			}
		}
		n = ((st->size_b + 3) / st->chunk) + 1;
	}
	sort_three_nums(st);
}
*/
void	push_chunks_to_b(t_stack *st)
{
	int	n;
	int	top;
	int	item;

	//n = (max / st->chunk);
	//while (!is_empty(st, 'a'))
	n = (st->size_b / st->chunk) + 1;
	while (st->size_a > 3 && !sorted(st))
	{
		top = st->a[st->size_a - 1];
		//printf("\ta[%d]:'%d' s_b:'%d' s_a:'%d' n:'%d' chunk * n:'%d' \n", st->size_a - 1, top, st->size_b, st->size_a, n, st->chunk * n);
		if (top > st->chunk * n || top >= st->capacity - 3)
			rotate(st, 'a');
		else if (top <= st->chunk * n)
		{
			pop(&item, st, 'a');
			push(item, st, 'b');
			top = st->a[st->size_a - 1];
			if (st->capacity > 20 && (item < (st->chunk * n) - (st->chunk / 2)))
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
	int	index;
	int	ra[st->capacity];
	int	rb[st->capacity];

	while (st->size_b)
	{
		clac_r_in_a_for_each_b(st, ra, rb);

		calc_rotations(ra, rb, st->size_b, &index);

		spin(st, ra, rb, index);
		
		pop(&item, st, 'b');
		push(item, st, 'a');
		/*
		printf("a: '");
		print_array(st->a, st->size_a);
		printf("b: '");
		print_array(st->b, st->size_b);

		
		printf("a: '");
		int i = st->size_a;
		while (--i >= 0)
			printf("%d, ", st->a[i]);
		printf("\n");
		printf("b: '");
		i = st->size_b;
		while (--i >= 0)
			printf("%d, ", st->b[i]);
		printf("\n");
		*/
	}
	bring_min_to_top(st);
}

/*
void	prepare_for_min_spin(t_stack *st, int *ra)
{
	int	min_i;
	int	max_i;

	min_a_vs_min_b(ra, st->size_b, &min_i, &max_i);

	if (min_i <= max_i)	
	{
		if (rb_vs_rrb(min_i, st->size_b) <= rb_vs_rrb(max_i, st->size_b))
			spin(st, ra_vs_rra(ra[min_i], st->size_a), direction(ra[min_i], st->size_a), rb_vs_rrb(min_i, st->size_b), direction(min_i, st->size_b));
		else
			spin(st, ra_vs_rra(ra[max_i], st->size_a), direction(ra[max_i], st->size_a), rb_vs_rrb(max_i, st->size_b), direction(max_i, st->size_b));
	}
	else
	{
		if (rb_vs_rrb(max_i, st->size_b) <= rb_vs_rrb(min_i, st->size_b))
			spin(st, ra_vs_rra(ra[max_i], st->size_a), direction(ra[max_i], st->size_a), rb_vs_rrb(max_i, st->size_b), direction(max_i, st->size_b));
		else
			spin(st, ra_vs_rra(ra[min_i], st->size_a), direction(ra[min_i], st->size_a), rb_vs_rrb(min_i, st->size_b), direction(min_i, st->size_b));
	}
}
int	direction(int index, int size)
{
	if (index <= size / 2)
		return (1);
	else
		return (-1);
}

int	ra_vs_rra(int index, int size_a)
{
	if (index <= size_a / 2) // ra
		return (index);
	else // rra
		return (size_a - index);
}

int	rb_vs_rrb(int index, int size_b)
{
	if (index <= size_b / 2) // rb
		return (index);
	else // rrb
		return (size_b - index);
}
int		rotations(int *ra, int *rb, int i)
{
	if (ra[i] >= 0 && rb[i] >= 0) //both ra rb are (+)
	{
		if (ra[i] >= rb[i])
			return (ra[i]);
		return (rb[i]);
	}
	if (ra[i] < 0 && rb[i] < 0) // both ra rb are (-)
	{
		if (ra[i] <= rb[i])
			return (abs(ra[i]));
		return (abs(rb[i]));
	}
	// ra (+/-) .. rb (+/-)
	return (abs(ra[i]) + abs(rb[i]));
}
*/

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
/*	
	printf(" ra[ ");
	i = -1;
	while (++i < st->size_b)
		printf("%d, ", ra[i]);
	printf("]\n");
	printf(" rb[ ");
	i = -1;
	while (++i < st->size_b)
		printf("%d, ", rb[i]);
	printf("]\n");
*/
}

void	calc_rotations(int *ra, int *rb, int size, int *index)
{
	int i;
	int	rotations[size];

	i = -1;
	while (++i < size)
	{
		if (ra[i] >= 0 && rb[i] >= 0) //both ra rb are (+)
		{
			if (ra[i] >= rb[i])
				rotations[i] = ra[i];
			else
				rotations[i] = rb[i];
		}
		else if (ra[i] < 0 && rb[i] < 0) // both ra rb are (-)
		{
			if (ra[i] <= rb[i])
				rotations[i] = abs(ra[i]);
			else
				rotations[i] = abs(rb[i]);
		}
		else// ra (+/-) .. rb (+/-)
			rotations[i] = abs(ra[i]) + abs(rb[i]);
	}
	*index = 0;
	while (!is_min(rotations, size, rotations[*index]))
		*index += 1;
	/*
	printf("rt-ns[ ");
	i = -1;
	while (++i < size)
		printf("%d, ", rotations[i]);
	printf("]\n");
	printf("index:'%d'\n", *index);
	*/
}

int		abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/*
void	min_a_vs_min_b(int *ra, int size, int *min_i, int *max_i)
{
	//int	i;
	//int	min;
	//int	max;

	*min_i = 0;
	while (!is_min(ra, size, ra[*min_i]))
		*min_i += 1;
	*max_i = 0;
	while (!is_max(ra, size, ra[*max_i]))
		*max_i += 1;
	if (*max_i < *min_i)
	{
		i = *min_i;
		min = ra[i];
		while (++i < size)
			if (ra[i] == min)
				*min_i = i;
	}
	else if (*min_i < *max_i)
	{
		i = *max_i;
		max = ra[i];
		while (++i < size)
			if (ra[i] == max)
				*max_i = i;
	}
	printf(" min_i ra[%d]:'%d' max_i ra[%d]:'%d'  size:'%d'\n", *min_i, ra[*min_i], *max_i, ra[*max_i], size);
}
*/
void	spin(t_stack *st, int *ra, int *rb, int i)
{
	if (ra[i] >= 0 && rb[i] >= 0)// rr ra rb
		rr_ra_rb(st, ra[i], rb[i]);
	else if (ra[i] < 0 && rb[i] < 0)// rrr rra rrb
		rrr_rra_rrb(st, abs(ra[i]), abs(rb[i]));
	else
	{
		if (ra[i] >= 0 && rb[i] < 0)// ra and rrb
		{
			rr_ra_rb(st, ra[i], 0);
			rrr_rra_rrb(st, 0, abs(rb[i]));
		}
		if (ra[i] < 0 && rb[i] >= 0)// rra and rb
		{
			rrr_rra_rrb(st, abs(ra[i]), 0);
			rr_ra_rb(st, 0, rb[i]);
		}
	}
}

void	rr_ra_rb(t_stack *st, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rotate(st, 'r');
		a--;
		b--;
	}
	while (a-- > 0)
		rotate(st, 'a');
	while (b-- > 0)
		rotate(st, 'b');
}

void	rrr_rra_rrb(t_stack *st, int a, int b)
{
	while (a > 0 && b > 0)
	{
		reverse_rotate(st, 'r');
		a--;
		b--;
	}
	while (a-- > 0)
		reverse_rotate(st, 'a');
	while (b-- > 0)
		reverse_rotate(st, 'b');
}
/*
void	spin(t_stack *st, int spin_a, int a_direction, int spin_b, int b_direction)
{
	//if ((ra_rra[i] > st->size_a / 2) && (i > st->size_b / 2)) // rra and rrb
	printf("\tspin(spin_a:'%d' > '%d' .. spin_b:'%d' > '%d')\n", spin_a, a_direction, spin_b, b_direction);
	if (a_direction < 0 && b_direction < 0)
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
	else if (a_direction > 0 && b_direction > 0)
	{
	//else if ((ra_rra[i] < st->size_a / 2) && (i < st->size_b / 2)) // ra and rb
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
	else if (a_direction < 0 && b_direction > 0)
	{
	//else if ((ra_rra[i] > st->size_a / 2) && (i < st->size_b / 2)) // rra and rb
		while (spin_b-- > 0)
			direction_to_spin(st, 'b', 1);
		while (spin_a-- > 0)
			direction_to_spin(st, 'a', -1);
	}
	else if (a_direction > 0 && b_direction < 0)
	{
	//else if ((ra_rra[i] < st->size_a / 2) && (i > st->size_b / 2)) // ra and rrb
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
int is_max(int *arr, int size, int item)
{
	int	i;

	i = -1;
	while (++i < size)
		if (item < arr[i])
			return (0);
	return (1);
}

*/
int	min_index(int *arr, int size)
{
	int	i;

	i = 0;
	while (!is_min(arr, size, arr[size - 1 - i]))
		i++;
	return (i);
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
	i = 1;
	while (item < st->a[st->size_a - 1 - i])
		i++;
	if (item > st->a[st->size_a - 1 - i])
		while (item > st->a[st->size_a - 1 - i])
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
	{
		i = st->size_a - i;
		while (i-- > 0)
			reverse_rotate(st, 'a');
	}
}
