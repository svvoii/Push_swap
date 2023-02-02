/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/02 14:51:10 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing_unsorted_nums(int *a, int *sorted, int len)
{
	int i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (a[i] == sorted[j])
			{
				a[i] = j;
				break ;
			}
		}
	}
}

int	main()
{
	int	len = 10;
	int	min = -99;
	int	max = 99;
	int	a[len];
	int	sorted[len];
	int	index[len];
	t_stack	*stack_a;

	get_rand_nums(a, len, min, max);
	for (int i = len - 1; i >= 0; i--)
	{
		sorted[i] = a[i];
		printf("%d\t", a[i]);
	}
	printf("\n");

	merge_sort(sorted, 0, len - 1);
	indexing_unsorted_nums(a, sorted, len);

	stack_a = create_stack(len);
	fill_in_stack(stack_a, a);

	for (int i = 0; i < stack_a->size; i++)
		printf("%d\t", stack_a->collection[i]);
	printf("\ncapacity:'%d'\tsize:'%d'", stack_a->capacity, stack_a->size);
	printf("\n");
	if (is_full(stack_a))
		printf("stack a is full.\n");

	radix_sort(stack_a);

	for (int i = 0; i < stack_a->size; i++)
		printf("%d\t", stack_a->collection[i]);
	printf("\ncapacity:'%d'\tsize:'%d'\n", stack_a->capacity, stack_a->size);

	destroy_stack(stack_a);

	return (0);
}