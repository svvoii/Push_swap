/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/06 13:41:40 by sbocanci         ###   ########.fr       */
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

void	print_array(int *arr, int len)
{
	int i = -1;

	while (++i < len)
		printf("%d, ", arr[i]);
	printf("\n");
}

void	print_index(int *arr, int len)
{
	int i = -1;

	while (++i < len)
		printf("[%d]", i);
	printf("\n");
}

int	main()
{
	int	len = 10;
	int	min = -99;
	int	max = 99;
	int	arr[len];
	int	sorted[len];
	t_stack	*a;
	t_stack	*b;

	get_rand_nums(arr, len, min, max);
	for (int i = len - 1; i >= 0; i--)
	{
		sorted[i] = arr[i];
		//printf("%d\t", arr[i]);
	}
	//printf("\n");
	merge_sort(sorted, 0, len - 1);
	indexing_unsorted_nums(arr, sorted, len);

	a = create_stack('a', len);
	b = create_stack('b', len);
	fill_in_stack(a, arr);

	//radix_sort(a, b);
	printf("a:\t");
	print_array(a->collection, a->size);
	printf("\t");
	print_index(a->collection, a->size);
	//printf("a > capacity:'%d'\tsize:'%d'\n", a->capacity, a->size);
	sort_stack(a, b);

	printf("a:\t");
	print_array(a->collection, a->size);
	printf("\t");
	print_index(a->collection, a->size);
	//printf("a > capacity:'%d'\tsize:'%d'\n", a->capacity, a->size);
/*
*/
	destroy_stack(a);
	//destroy_stack(b);

	return (0);
}