/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:40 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_argv(int ac, char **av);
void	atoi_str_to_stack(char **av, t_stack *stack);
long	ft_atoi(char *str, t_stack *stack);
int		unique_values(int *st, int size);
int		sorted(t_stack *st);
void	push_swap_to_b(t_stack *st);
void	find_max(t_stack *st, int *max, int *index);
void	push_swap_back_to_a(t_stack *st);
void	indexing_unsorted_nums(int *a, int *sorted, int len);
void	print_array(int *arr, int len);
void	print_index(int *arr, int len);
void	ft_quit(t_stack *st, int err);

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac < 2)
		exit (0);
	if (!valid_argv(ac, av))
		ft_quit(st, 1);
	if (!create_stacks_a_b(stacks, ac - 1))
		ft_quit(st, 1);
	atoi_str_to_stack(av, stacks);
	if (!unique_values(stacks->a, stacks->size_a));
		ft_quit(st, 1);
	if (sorted(stacks))
		ft_quit(st, 0);
	push_swap_to_b(stacks);
	push_swap_back_to_a(stacks);

	merge_sort(sorted, 0, len - 1);
	indexing_unsorted_nums(arr, sorted, len);

	fill_in_stack_a(stacks, arr);

	//radix_sort(a, b);
/*
	printf("a:\t");
	print_array(a->collection, a->size);
	printf("\t");
	print_index(a->collection, a->size);
	//printf("a > capacity:'%d'\tsize:'%d'\n", a->capacity, a->size);


	printf("a:\t");
	print_array(a->collection, a->size);
	printf("\t");
	print_index(a->collection, a->size);
	//printf("a > capacity:'%d'\tsize:'%d'\n", a->capacity, a->size);
*/
	sort_stack(a, b);

	destroy_stack(a);
	//destroy_stack(b);

	return (0);
}

int	valid_argv(int ac, char **av)
{
	int	i;
	int	j;

	if (!av || !*av)
		return (0);
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (0);
		}
	}
	return (1);
}

void	atoi_str_to_stack(char **av, t_stack *st)
{
	long	num;
	int		size;
	int		i;

	size = -1;
	i = st->capacity + 1;
	while (--i > 0)
	{
		num = ft_atoi(av[i], st);
		if (num > 2147483647 || num < -2147483648)
			ft_quit(st, 1);
		st->a[size++] = (int)num;
	}
	st->size_a = size;
}

long	ft_atoi(char *str, t_stack *stack)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i + 1] < '0' || str[i + 1] > '9')
			ft_quit(stack, 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((long)str[i] - '0');
		i++;
	}
	return (num * sign);
}

int		unique_values(int *st, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (st[i] == st[j])
				return (0);
	}
	return (1);
}

int	sorted(t_stack *st)
{
	int	i;

	i = st->size_a;
	while (--i > 0)
	{
		if (st->a[i] > st->a[i - 1])
			return (0);
	}
	return (1);
}

void	push_swap_to_b(t_stack *st)
{
	int	i;
	int	n;
	int	chunk;
	int	top;

	i = 1;
	n = 1;
	chunk = ((st->size_a - 1) / 10) + 10;
	while (!is_empty(st, 'a'))
	{
		top = st->size_a - 1;
		if (st->a[top] < chunk * n)
		{
			pb(st);
			top = st->size_b - 1;
			if (top && st->b[top] < (chunk * n) - (chunk / 2))
				rb(st->b, st->size_b);
			i++;
		}
		else
			while (st->a[top] >= chunk * n)
				ra(st->a, st->size_a);
		if (i == chunk * n)
			n++;
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

void	push_swap_back_to_a(t_stack *st)
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
			else
				rrb(st->b, st->size_b);
		}
		pa(st);
	}
}

void	indexing_unsorted_nums(int *a, int *sorted, int len)
{
	int i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (a[i] == sorted[j])
			{
				a[i] = j;
				break ;
			}
		}
	}
}

void	print_array(int *arr, int len)
{
	int i = -1;

	while (++i < len)
		printf("%d, ", arr[i]);
	printf("\n");
}

void	print_index(int *arr, int len)
{
	int i = -1;

	while (++i < len)
		printf("[%d]", i);
	printf("\n");
}

void	ft_quit(t_stack *st, int err)
{
	if (err == 1 || err == 5)
		write(1, "Error\n", 6);
	if (err != 1 || err != 5)
	{
		free(st->a);
		free(st->b);
	}
	exit (0);
}