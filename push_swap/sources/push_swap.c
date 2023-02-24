/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/24 12:34:08 by sbocanci         ###   ########.fr       */
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
	printf("\n");
}

void	print_array(int *arr, int size)
{
	while (--size >= 0)
		printf("%d, ", arr[size]);
	printf("\n");
}

char	**copy_to_2d_str_arr(int ac, char **av, int *count)
{
	char	**str;
	int		i;

	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		i = 0;
		while (str[i])
			i++;
	}
	else
	{
		str = (char **)malloc(sizeof(char *) * (ac - 1));
		i = -1;
		while (++i < ac - 1)
		{
			str[i] = av[i + 1];
		}
	}
	*count = i;
	return (str);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	**str;
	int		count;

	if (ac < 2)
		exit (0);
	count = 0;
	str = copy_to_2d_str_arr(ac, av, &count);
	//print_av(av, ac);
	//printf("count:'%d'\n", ac);
	if (!valid_argv(count, str))
	{
		write(1, "Error\n", 6);
		exit (0);
		//ft_quit(stack, 1);
	}
	stack = create_stacks_a_b(count);
	if (!stack)
		write(1, "Error\n", 6);
	atoi_str_to_stack(str, stack);
	//printf("atoi to stack OK!!\tcount:'%d'\n", count);
	if (!unique_values(stack->a, stack->size_a))
		ft_quit(stack, 1);
	if (sorted(stack))
		ft_quit(stack, 0);
	if (count < 10)
	{
		sort_small_stack(stack);
	}
	else
	{
		indexing(stack);
		//print_array(stack->a, stack->size_a);
		push_chunks_to_b(stack);
		//calc_and_push_to_b(stack);
/*
		printf("a: '");
		print_array(stack->a, stack->size_a);
		printf("b: '");
		print_array(stack->b, stack->size_b);
*/
		smart_push_back_to_a(stack);
		//push_swap_back_to_a(stack);
		//print_array(stack->a, stack->size_a);
	}
	//print_array(stack->a, stack->size_a);
	//printf("count: '%d'\n", stack->count);
	ft_quit(stack, 0);
	return (0);
}

int	valid_argv(int count, char **str)
{
	int	i;
	int	j;

	if (!str || !*str)
		return (0);
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (str[i][++j])
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if ((str[i][j] < '0' || str[i][j] > '9'))
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
