/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 12:52:32 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stacks_a_b(t_stack *st, int capacity);
void	atoi_str_to_stack(t_stack *st, int ac);
long	ft_atoi(char *s, t_stack *st, int ac);
void	merge_sort(int *arr, int start, int end);

/* Allocating memory for a structure and for int arr of given capacity */
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
	return (st);
}

/* Next two f() convert chars from 2d char arr into int to stack a */
void	atoi_str_to_stack(t_stack *st, int ac)
{
	long	num;
	int		size;
	int		i;

	size = 0;
	i = st->capacity;
	while (--i >= 0)
	{
		num = ft_atoi(st->input_str[i], st, ac);
		if (num > 2147483647 || num < -2147483648)
			free_and_quit(st, ac, 1);
		st->a[size] = (int)num;
		size++;
	}
	st->size_a = size;
	if (size > 20)
		st->chunk = size / 3;
	else
		st->chunk = size;
}

/* this atoi checks for non digit and stops the program if any */
long	ft_atoi(char *s, t_stack *st, int ac)
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
		free_and_quit(st, ac, 1);
	return (num * sign);
}

/* merge sort algo is used for indexing unsorted nums. See indexing() */
static void	merge(int arr[], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int	*buf;

	buf = (int *)malloc(sizeof(int) * (end + 1));
	i = start - 1;
	while (++i <= end)
		buf[i] = arr[i];
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (buf[i] <= buf[j])
			arr[k++] = buf[i++];
		else
			arr[k++] = buf[j++];
	}
	while (i <= mid)
		arr[k++] = buf[i++];
	while (j <= end)
		arr[k++] = buf[j++];
	free(buf);
}

void	merge_sort(int *arr, int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = start + (end - start) / 2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
