/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_psw_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 12:33:41 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_nums(t_stack *st);
int		min_index(int *arr, int size);
int		is_min(int *arr, int size, int item);
int		find_bigger(t_stack *st, int item);
int		find_smaller(t_stack *st, int item);

// Conditions to sort a when there is only 3 values in it
void	sort_three_nums(t_stack *st)
{
	if (st->size_a != 3)
		return ;
	while (!sorted(st))
	{
		if (st->a[0] > st->a[1])
		{
			if (st->a[1] < st->a[2] && st->a[2] < st->a[0])
				swap(st, 'a', 1);
			else
				rotate(st, 'a', 1);
		}
		else if (st->a[0] < st->a[1])
		{
			if (st->a[0] < st->a[2] && st->a[1] > st->a[2])
				reverse_rotate(st, 'a', 1);
			else
				swap(st, 'a', 1);
		}
	}
}

int	min_index(int *arr, int size)
{
	int	i;

	i = 0;
	while (!is_min(arr, size, arr[size - 1 - i]))
		i++;
	return (i);
}

int	is_min(int *arr, int size, int item)
{
	int	i;

	i = -1;
	while (++i < size)
		if (item > arr[i])
			return (0);
	return (1);
}

int	find_bigger(t_stack *st, int item)
{
	int	i;

	i = 0;
	while (item > st->a[st->size_a - 1 - i])
		i++;
	return (i);
}

int	find_smaller(t_stack *st, int item)
{
	int	i;

	if (item < st->a[st->size_a - 1] && item > st->a[0])
		return (0);
	i = 1;
	while (item < st->a[st->size_a - 1 - i])
		i++;
	if (item > st->a[st->size_a - 1 - i])
		while (item > st->a[st->size_a - 1 - i])
			i++;
	return (i);
}
