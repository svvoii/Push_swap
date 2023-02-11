#include "../includes/p_swap.h"

void	push_sorted_to_a(t_stack *st);
void	mini_search(t_stack *st, int *i, int j);
void	push_sorted_to_b(t_stack *st);
void	indexing(t_stack *st);

void	indexing(t_stack *st)
{
	int i;
	int	j;
	int	buf[st->size_a];

	i = -1;
	while (++i < st->size_a)
		buf[i] = st->a[i];
	merge_sort(buf, 0, i - 1);
/*
	printf("\na:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\nb:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", buf[i]);
	printf("\n");
*/
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
/*
	printf("a:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\n");
*/
}

void	first_push_to_b(t_stack *st)
{
	int i;
	int	n;
	int chunk;
	int top;

	i = 1;
	n = 1;
	chunk = ((st->size_a - 1) / 10) + 10;
	//printf("push_to_b\t");
	//printf("(chunk:'%d' * n:'%d') == '%d'\n", chunk, n, chunk * n);
	while (!is_empty(st, 'a'))
	{
		top = st->size_a - 1;
		//printf("st->a[%d]:'%d'\n", top, st->a[top]);
		if (st->a[top] < chunk * n)
		{
			pb(st);
			top = st->size_b - 1;
			//printf("\tst->b[%d]:'%d' < '%d'\n", top, st->b[top], (chunk * n) - (chunk / 2));
			if (top && st->b[top] < (chunk * n) - (chunk / 2))
				rb(st->b, st->size_b);
			i++;
		}
		else
		{
			while (st->a[top] >= chunk * n)
			{
				//printf("\tst->a[%d]:'%d' .. a[%d]:'%d'\n", top, st->a[top], top - 1, st->a[top - 1]);
				ra(st->a, st->size_a);
			}
		}
		if (i == chunk * n)
			n++;
		//printf("---\tn:'%d'---\n", n);
	}
	//printf("..end push_to_b\n");
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

void	pushback_to_a(t_stack *st)
{
	int	top;
	int	max;
	int	index;

	while (!is_empty(st, 'b'))
	{
		find_max(st, &max, &index);
		top = st->size_b - 1;
		while (st->b[top] != max)
		{
			if (index >= top / 2)
				rb(st->b, st->size_b);
			else if (index < top / 2)
				rrb(st->b, st->size_b);
		}
		pa(st);
	}
}
