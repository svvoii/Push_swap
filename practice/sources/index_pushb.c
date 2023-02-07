#include "p_swap.h"

void	indexing(t_stack *st)
{
	int	i;
	int	j;
	int	count;
	int	*new_stack;

	i = -1;
	count = 0;
	new_stack = (int *)malloc(sizeof(int) * (st->top_a + 1));
	while (++i <= st->top_a)
	{
		j = -1;
		while (++j <= st->top_a)
			if (st->a[j] < st->b[i])
				count++;
		new_stack[i] = count;
		count = 0;
	}
	free(st->a);
	st->a = new_stack;
}

void	push_sorted_to_b(t_stack *st)
{
	int i;
	int	n;
	int chunk;

	i = 1;
	n = 1;
	chunk = (st->top_a / 10) + 10;
	while (st->top_a >= 0)
	{
		if (st->a[st->top_a] < chunk * n)
		{
			pb(st->a, &st->top_a, st->b, &st->top_b);
			if (st->b[st->top_b] < (chunk * n) - (chunk / 2))
				rb(st->b, st->top_b, '1');
			i++;
		}
		else
		{
			while (st->a[st->top_a] >= chunk * n)
				ra(st->a, st->top_a, '1');
		}
		if (i == chunk * n)
			n++;
	}
}

void	mini_search(t_stack *st, int *i, int j)
{
	int	f_j;

	f_j = -1;
	while (*i <= st->top_b)
	{
		f_j = find_j(st->b, st->top_b, j);
		if (f_j >= (st->top_b / 2))
		{
			if (st->b[st->top_b] != j)
				rb(st->b, st->top_b, '1');
		}
		else if (f_j < (st->top_b / 2))
		{
			if (st->b[st->top_b] != j)
				rrb(st->b, st->top_b, '1');
		}
		*i++;
	}
}

void	push_sorted_to_a(t_stack *st)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = st->top_b;
	j = st->b[st->top_b];
	while (k + 1)
	{
		i = -1;
		while (++i <= st->top_b)
		{
			if (j < st->b[i])
				j = st->b[i];
		}
		i = -1;
		mini_search(st, &i, j);
		pa(st->a, &st->top_a, st->b, &st->top_b);
		j = st->b[st->top_b];
		k--;
	}
}
