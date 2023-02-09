#include "../includes/p_swap.h"

void	pa(t_stack *st);
void	pb(t_stack *st);
void	sa(int *a, int size);
void	sb(int *b, int size);
void	ss(int *a, int size_a, int *b, int size_b);
void	ra(int *a, int size);
void	rb(int *b, int size);
void	rr(int *a, int size_a, int *b, int size_b);
void	rra(int *a, int size);
void	rrb(int *b, int size);
void	rrr(int *a, int size_a, int *b, int size_b);

void	pa(t_stack *st)
{
	int	item;

	pop(st, 'b', &item);
	push(st, 'a', item);
	//write(1, "pa\n", 3);
}

void	pb(t_stack *st)
{
	int	item;

	pop(st, 'a', &item);
	push(st, 'b', item);
	//write(1, "pb\n", 3);
}

void	sa(int *a, int size)
{
	if (size > 1)
		swap(&a[size - 1], &a[size - 2], 'a');
}

void	sb(int *b, int size)
{
	if (size > 1)
		swap(&b[size - 1], &b[size - 2], 'b');
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	swap(&a[size_a - 1], &a[size_a - 2], 's');
	swap(&b[size_b - 1], &b[size_b - 2], 's');
	write(1, "ss\n", 3);
}

void	ra(int *a, int size)
{
	rotate(a, size, 'a');
}

void	rb(int *b, int size)
{
	rotate(b, size, 'b');
}

void	rr(int *a, int size_a, int *b, int size_b)
{
	rotate(a, size_a, 'r');
	rotate(b, size_b, 'r');
	write(1, "rr\n", 3);
}

void	rra(int *a, int size)
{
	reverse_rotate(a, size, 'a');
}

void	rrb(int *b, int size)
{
	reverse_rotate(b, size, 'b');
}

void	rrr(int *a, int size_a, int *b, int size_b)
{
	reverse_rotate(a, size_a, 'r');
	reverse_rotate(b, size_b, 'r');
	write(1, "rrr\n", 4);
}
