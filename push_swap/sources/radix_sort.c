/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:40:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/02 14:54:07 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack *a)
{
	t_stack	*b;
	int		i;
	int		j;
	int		r;
	int		peek_value;

	b = create_stack(a->capacity);
	i = 10;
	while (--i >= 0)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->collection[j] % 10 == i)
			{
				if (j < a->size - 1)
				{
					r = j + 1;
					while (r >= 0)
					{
						rotate(a->collection, a->size);
					}
				}
				pop(a, &peek_value);
				push(b, peek_value);
				j = -1;
			}
		}
	}
}
