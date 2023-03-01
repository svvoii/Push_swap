/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/01 15:36:41 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**copy_to_2d_str_arr(int ac, char **av, int *count);
int		unique_values(t_stack *st);
int		sorted(t_stack *st);
void	free_and_quit(t_stack *st, char **str, int ac, int err);

int	main(int ac, char **av)
{
	t_stack	stack;
	t_stack	*st;
	char	**str;
	int		count;

	st = &stack;
	if (ac < 2)
		exit (0);
	str = copy_to_2d_str_arr(ac, av, &count);
	create_stacks_a_b(st, count);
	atoi_str_to_stack(str, st, ac);
	if (!unique_values(st))
		free_and_quit(st, str, ac, 1); // free stack and str print err
	if (sorted(st))
		free_and_quit(st, str, ac, 0); // free stack and str
	if (count < 20)
		sort_small_stack(st);
	else
	{
		indexing(st);
		//print_array(st->a, st->size_a);
		push_chunks_to_b(st);
		//calc_and_push_to_b(st);
		printf("count: '%d'\n", st->count);
		smart_push_back_to_a(st);
		//push_swap_back_to_a(st);
	}
	free_and_quit(st, str, ac, 0); // free stack and str
	return (0);
	//print_array(st->a, st->size_a);
}

char	**copy_to_2d_str_arr(int ac, char **av, int *count)
{
	char	**str;
	int		i;

	*count = 0;
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
			str[i] = av[i + 1];
	}
	*count = i;
	return (str);
}

int	unique_values(t_stack *st)
{
	int	i;
	int	j;

	i = -1;
	while (++i < st->size_a)
	{
		j = i;
		while (++j < st->size_a)
			if (st->a[i] == st->a[j])
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

void	free_and_quit(t_stack *st, char **str, int ac, int err)
{
	int	size;

	size = st->capacity;
	while (ac == 2 && size >= 0)
		free(str[size--]);
	free(str);
	if (err)
		write(1, "Error\n", 6);
	if (st->a)
		free(st->a);
	if (st->b)
		free(st->b);
	exit (0);
}

/*
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
*/