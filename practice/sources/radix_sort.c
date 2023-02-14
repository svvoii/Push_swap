/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:40:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/04 17:06:07 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	digit(int num, int turn)
{
	if (turn == 1)
		return (num % 10);
	else if (turn == 2)
		return (num / 10);
}

void	sorting(t_stack *to_sort, t_stack *empty, int *turn)
{
	int		i;
	int		j;
	int		r;
	int		peek_value;

	i = 10;
	//printf("\tturn:'%d'\n", *turn);
	while (--i >= 0)
	{
		j = -1;
		while (++j < to_sort->size)
		{
			if (digit(to_sort->collection[j], *turn) == i)
			{
				r = 0;
				while (to_sort->collection[r] != to_sort->size - 1)
					r++;
				while (to_sort->collection[to_sort->size - 1] != to_sort->size - 1)
				{
					if (r < to_sort->size / 2)
						reverse_rotate(to_sort);
					else
						rotate(to_sort);
				}
				//printf("num:'%d' > digit:'%d'\t", to_sort->collection[j], digit(to_sort->collection[j], *turn));
				pop(to_sort, &peek_value);
				push(empty, peek_value);
				//print_array(empty->collection, empty->size);
				//print_array(to_sort->collection, to_sort->size);
				j = -1;
			}
		}
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	turn;

	turn = 1;
	while (turn < 3)
	{
		if (!is_empty(a))
			sorting(a, b, &turn);
		else
			sorting(b, a, &turn);
		turn++;
	}
}
