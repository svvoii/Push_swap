/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/14 16:31:26 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_argv(int ac, char **av);
int		unique_values(int *st, int size);
int		sorted(t_stack *st);
void	ft_quit(t_stack *st, int err);

void	print_av(char **av, int ac)
{
	int	i = 0;

	while (++i < ac)
		printf("%s ", av[i]);
	printf("|\tac:'%d'\n", ac);
}

void	print_array(int *arr, int size)
{
	while (--size >= 0)
		printf("%d, ", arr[size]);
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		exit (0);
	print_av(av, ac);
	if (!valid_argv(ac, av))
	{
		write(1, "Error\n", 6);
		exit (0);
		//ft_quit(stack, 1);
	}
	//printf("valid argsuments!!\n");
	stack = create_stacks_a_b(ac - 1);
	if (!stack)
		write(1, "Error\n", 6);
	atoi_str_to_stack(av, stack);
	if (!unique_values(stack->a, stack->size_a))
		ft_quit(stack, 1);
	if (sorted(stack))
		ft_quit(stack, 0);
	if (ac < 20)
	{
		sort_small_stack(stack);
	}
	else
	{
		push_swap_to_b(stack);
		push_swap_back_to_a(stack);
	}
	print_array(stack->a, stack->size_a);
	ft_quit(stack, 0);
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

int	unique_values(int *st, int size)
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

void	ft_quit(t_stack *st, int err)
{
	if (err == 1 || err == 5)
		write(1, "Error\n", 6);
	if (err != 1 || err != 5)
	{
		if (st->a)
			free(st->a);
		if (st->b)
			free(st->b);
		if (st)
			free(st);
	}
	exit (0);
}
