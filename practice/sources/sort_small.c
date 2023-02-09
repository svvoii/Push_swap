#include "../includes/p_swap.h"

void	sort_5nb(t_stack *st, int count);
void	push_to_b(t_stack *st);
int	find_i(int *a, int size, int	find);
int	find_small(int *a, int size);
void	sort_3nb(t_stack *st, int count);

void	sort_3nb(t_stack *st, int count)
{
	if (count == 3)
	{
		if (!sorted(st))
			sa(st->a, st->size_a, '1');
		return ;
	}
	while (!sorted(st))
	{
		if (st->a[st->size_a] > st->a[(st->size_a) - 1])
		{
			sa(st->a, st->size_a, '1');
			if (!sorted(st))
				rra(st->a, st->size_a, '1');
		}
		else
			rra(st->a, st->size_a, '1');
	}
}

int	find_small(int *a, int size)
{
	int	i;
	int	j;

	i = size;
	j = a[size];
	while (i >= 0)
	{
		if (j > a[i])
			j = a[i];
		i--;
	}
	return (j);
}

int	find_i(int *a, int size, int	find)
{
	int	i;

	i = size;
	while (i >= 0)
	{
		if (a[i] == find)
			return (i);
		i--;
	}
	return (-1);
}

void	push_to_b(t_stack *st)
{
	int j;

	j = find_i(st->a, st->size_a, find_small(st->a, st->size_a));
	if (j == st->size_a)
	{
		pb(st->a, &st->size_a, st->b, &st->size_b);
		return ;
	}
	if (j < st->size_a / 2)
		while (st->a[st->size_a] != find_small(st->a, st->size_a))
			rra(st->a, st->size_a, '1');
	else
		while (st->a[st->size_a] != find_small(st->a, st->size_a))
			ra(st->a, st->size_a, '1');
	pb(st->a, &st->size_a, st->b, &st->size_b);
}

void	sort_5nb(t_stack *st, int count)
{
	push_to_b(st);
	if (count == 6)
		push_to_b(st);
	sort_3nb(st, 4);
	pa(st->a, &st->size_a, st->b, &st->size_b);
	if (count == 6)
		pa(st->a, &st->size_a, st->b, &st->size_b);
}
