/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/21 19:28:22 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Allocating memory for a structure and for int arr of given capacity
t_stack	*create_stacks_a_b(int capacity)
{
	t_stack *st;

	if (capacity <= 0)
		return (NULL);
	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->a = malloc(sizeof(int) * capacity);
	if (!st->a)
	{
		free(st);
		return (NULL);
	}
	st->b = malloc(sizeof(int) * capacity);
	if (!st->b)
	{
		free(st->a);
		free(st);
		return (NULL);
	}
	st->capacity = capacity;
	st->size_a = 0;
	st->size_b = 0;
	st->count = 0;
	return (st);
}

// Returns 1 (true) if the stack is empty.
int	is_empty(t_stack *stack, char name)
{
	if (name == 'a')
		return (stack->size_a == 0);
	else if (name == 'b')
		return (stack->size_b == 0);
	return (0);
}

// Following two f() convert chars from av to int and store in stack a
void	atoi_str_to_stack(char **str, t_stack *st)
{
	long	num;
	int		size;
	int		i;

	size = 0;
	i = st->capacity;
	while (--i >= 0)
	{
		num = ft_atoi(str[i], st);
		if (num > 2147483647 || num < -2147483648)
			ft_quit(st, 1);
		//st->b[size] = 0;
		st->a[size] = (int)num;
		size++;
	}
	st->size_a = size;
	if (size < 300)
		st->chunk = (size / 4);
	else if (size >= 300)
		st->chunk = (size / 9);
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
