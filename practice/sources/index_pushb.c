#include "../includes/p_swap.h"

void	push_sorted_to_a(t_stack *st);
void	mini_search(t_stack *st, int *i, int j);
void	push_sorted_to_b(t_stack *st);
void	indexing(t_stack *st);

void	indexing(t_stack *st)
{
	int i;
	int	j;

	merge_sort(st->b, 0, st->size_b - 1);

	printf("\na:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\nb:\t");
	for (int i = 0; i < st->size_b; i++)
		printf("%d, ", st->b[i]);
	printf("\n");

	i = -1;
	while (++i < st->size_a)
	{
		j = -1;
		while (++j < st->size_a)
		{
			if (st->a[i] == st->b[j])
			{
				st->a[i] = j;
				break ;
			}
		}
	}
	printf("a:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\n");
}
/*
void	indexing(t_stack *st)
{
	int	i;
	int	j;
	int	count;
	int	*new_stack;

	i = -1;
	count = 0;
	new_stack = (int *)malloc(sizeof(int) * (st->size_a));
	while (++i < st->size_a)
	{
		j = -1;
		while (++j < st->size_a)
		{
			if (st->a[j] < st->b[i])
				count++;
			printf("\nst->a[%d]:'%d' < st->b[%d]:'%d'\tcount:'%d'", j, st->a[j], i, st->b[i], count);
		}
		new_stack[i] = count;
		count = 0;
	}
	free(st->a);
	st->a = new_stack;
}
*/
void	push_sorted_to_b(t_stack *st)
{
	int i;
	int	n;
	int chunk;

	i = 1;
	n = 1;
	chunk = ((st->size_a - 1) / 10) + 10;
	printf("push_to_b\n");
	while (st->size_a >= 0)
	{
		if (st->a[st->size_a - 1] < chunk * n)
		{
			printf("st->a[%d]:'%d' < chunk:'%d' * n:'%d'\n", st->size_a - 1, st->a[st->size_a - 1], chunk, n);
			//pb(st->a, &st->size_a, st->b, &st->size_b);
			pb(st);
			if (st->b[st->size_b - 1] < (chunk * n) - (chunk / 2))
				rb(st->b, st->size_b);
			i++;
		}
		else
		{
			printf("st->a[%d]:'%d'\n", st->size_a, st->a[st->size_a]);
			while (st->a[st->size_a - 1] >= chunk * n)
				ra(st->a, st->size_a);
		}
		if (i == chunk * n)
			n++;
	}
	printf("..end push_to_b\n");
}

void	mini_search(t_stack *st, int *i, int j)
{
	int	f_j;

	f_j = -1;
	while (*i <= st->size_b)
	{
		f_j = find_j(st->b, st->size_b, j);
		if (f_j >= (st->size_b / 2))
		{
			if (st->b[st->size_b] != j)
				rb(st->b, st->size_b);
		}
		else if (f_j < (st->size_b / 2))
		{
			if (st->b[st->size_b] != j)
				rrb(st->b, st->size_b);
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
	k = st->size_b;
	j = st->b[st->size_b];
	while (k + 1)
	{
		i = -1;
		while (++i <= st->size_b)
		{
			if (j < st->b[i])
				j = st->b[i];
		}
		i = -1;
		mini_search(st, &i, j);
		pa(st);
		j = st->b[st->size_b];
		k--;
	}
}
