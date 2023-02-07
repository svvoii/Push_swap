#include "p_swap.h"

void	pa(int *a, int *top_a, int *b, int *top_b);
void	pb(int *a, int *top_a, int *b, int *top_b);
void	sa(int *a, int top, char c);
void	sb(int *b, int top, char c);
void	ss(int *a, int top_a, int *b, int top_b);
void	ra(int *a, int top, char c);
void	rb(int *b, int top, char c);
void	rr(int *a, int top_a, int *b, int top_b);
void	rra(int *a, int top, char c);
void	rrb(int *b, int top, char c);

void	pa(int *a, int *top_a, int *b, int *top_b)
{
	if (*top_b > -1)
	{
		a[*top_a + 1] = b[*top_b];
		*top_b -= 1;
		*top_a += 1;
	}
	write(1, "pa\n", 3);
}

void	pb(int *a, int *top_a, int *b, int *top_b)
{
	if (*top_a > -1)
	{
		b[*top_b + 1] = a[*top_a];
		*top_a -= 1;
		*top_b += 1;
	}
	write(1, "pb\n", 3);
}

void	sa(int *a, int top, char c)
{
	int	tmp;

	if (top >= 1)
	{
		tmp = a[top];
		a[top] = a[top - 1];
		a[top - 1] = tmp;
	}
	if (c != '2')
		write(1, "sa\n", 3);
}

void	sb(int *b, int top, char c)
{
	int	tmp;

	if (top >= 1)
	{
		tmp = b[top];
		b[top] = b[top - 1];
		b[top - 1] = tmp;
	}
	if (c != '2')
		write(1, "sb\n", 3);
}

void	ss(int *a, int top_a, int *b, int top_b)
{
	sa(a, top_a, '2');
	sb(b, top_b, '2');
	write(1, "ss\n", 3);
}

void	ra(int *a, int top, char c)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(a);
		exit (0);
	}
	tmp[0] = a[top];
	i = top + 1;
	while (--i > 0)
	{
		tmp[i] = a[i - 1];
	}
	i = -1;
	while (++i <= top)
	{
		a[i] = tmp[i];
	}
	free(tmp);
	if (c != '2')
		write(1, "ra\n", 3);
}

void	rb(int *b, int top, char c)
{
	int	i;
	int	*tmp;

	top = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(b);
		exit (0);
	}
	tmp[0] = b[top];
	i = top + 1;
	while (--i > 0)
	(
		tmp[i] = b[i - 1];
	)
	i = -1;
	while (++i <= top)
	{
		b[i] = tmp[i];
	}
	free(tmp);
	if (c != '2')
		write(1, "rb\n", 3);
}

void	rr(int *a, int top_a, int *b, int top_b)
{
	ra(a, top_a, '2');
	rb(b, top_b, '2');
	write(1, "rr\n", 3);
}

void	rra(int *a, int top, char c)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(a);
		exit (0);
	}
	i = top + 1;
	while (--i > 0)
	{
		tmp[i - 1] = a[i];
	}
	tmp[top] = a[0];
	i = -1;
	while (++i <= top)
	{
		a[i] = tmp[i];
	}
	free(tmp);
	if (c != '2')
		write(1, "rra\n", 4);
}

void	rrb(int *b, int top, char c)
{
	int i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(b);
		exit (0);
	}
	i = top + 1;
	while (--i > 0)
	{
		tmp[i - 1] = b[i];
	}
	tmp[top] = b[0];
	i = -1;
	while (++i <= top)
	{
		b[i] = tmp[i];
	}
	free(tmp);
	if (c != '2')
		write(1, "rrb\n", 4);
}
