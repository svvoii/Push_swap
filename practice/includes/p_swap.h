#ifndef P_SWAP_H
# define P_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stab
{
    int	*a;
    int	*b;
    int	size_a;
    int	size_b;
	int	capacity;
}	t_stack;

void		pa(t_stack *st);
void		pb(t_stack *st);
void		sa(int *a, int size);
void		sb(int *b, int size);
void		ss(int *a, int size_a, int *b, int size_b);
void		ra(int *a, int size);
void		rb(int *b, int size);
void		rr(int *a, int size_a, int *b, int size_b);
void		rra(int *a, int size);
void		rrb(int *b, int size);
void		rrr(int *a, int size_a, int *b, int size_b);
int			find_j(int *t, int size, int j);
int			check_arg(int ac, char **av);
int			check_repeat(int *t, int size);
long long	ft_atoi(char *str, t_stack *stack);
void        indexing(t_stack *var);
void        push_sorted_to_b(t_stack *var);
void        push_sorted_to_a(t_stack *var);
int			sorted(t_stack *stack);
void        sort_3nb(t_stack *var, int c);
int			find_small(int *t, int size);
int			find_i(int *t, int size, int find);
void        push_to_b(t_stack *var);
void        sort_5nb(t_stack *var, int c);
void        quit(t_stack *va, int c);
int			check_space(char **v);
void		merge_sort(int *arr, int start, int end);
int			push(t_stack *stack, char s, int item);
int			pop(t_stack *stack, char s, int *item);
void		swap(int *a, int *b, char c);
void		rotate(int *stack, int size, char s);
void		reverse_rotate(int *stack, int size, char s);
int			is_full(t_stack *stack, char s);
int			is_empty(t_stack *stack, char s);

#endif