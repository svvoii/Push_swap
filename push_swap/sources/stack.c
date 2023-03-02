/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/02 14:33:32 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Allocating memory for a structure and for int arr of given capacity
t_stack	*create_stacks_a_b(t_stack *st, int capacity)
{
	st->a = malloc(sizeof(int) * capacity);
	if (!st->a)
		return (NULL);
	st->b = malloc(sizeof(int) * capacity);
	if (!st->b)
	{
		free(st->a);
		return (NULL);
	}
	st->capacity = capacity;
	st->size_a = 0;
	st->size_b = 0;
	st->count = 0;
	return (st);
}

// Following two f() convert chars from av to int and store in stack a
void	atoi_str_to_stack(char **str, t_stack *st, int ac)
{
	long	num;
	int		size;
	int		i;

	size = 0;
	i = st->capacity;
	while (--i >= 0)
	{
		num = ft_atoi(str, str[i], st, ac);
		if (num > 2147483647 || num < -2147483648)
			free_and_quit(st, str, ac, 1);
		st->a[size] = (int)num;
		size++;
	}
	st->size_a = size;
	st->chunk = st->size_a;
	if (st->size_a > 20)
		st->chunk = (st->size_a / 3);
}

long	ft_atoi(char **str, char *s, t_stack *st, int ac)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + ((long)s[i] - '0');
		i++;
	}
	if (s[i] && (s[i] < '0' || s[i] > '9'))
		free_and_quit(st, str, ac, 1); // free stack and str print err
	return (num * sign);
}
