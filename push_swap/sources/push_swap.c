/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 11:47:47 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**copy_to_2d_str_arr(int ac, char **av, int *count);
int		unique_values(t_stack *st);
int		sorted(t_stack *st);
void	free_and_quit(t_stack *st, int ac, int err);
void	print_instruction(char *s1, char s2);

/* treating the input with either split or arr of pointers */
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

/* check if values in stack a are unique */
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

void	free_and_quit(t_stack *st, int ac, int err)
{
	int	size;

	size = st->capacity;
	while (ac == 2 && size >= 0)
		free(st->input_str[size--]);
	free(st->input_str);
	if (err)
		write(1, "Error\n", 6);
	if (st->a)
		free(st->a);
	if (st->b)
		free(st->b);
	exit (err);
}

void	print_instruction(char *s1, char s2)
{
	ft_putstr_fd(s1, 1);
	ft_putchar_fd(s2, 1);
	ft_putchar_fd('\n', 1);
}
