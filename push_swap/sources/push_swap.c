/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/30 17:38:00 by sbocanci         ###   ########.fr       */
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

	get_rand_nums(a, len, min, max);
	for (int i = 0; i < len; i++)
	{
		sorted[i] = a[i];
		//printf("[%d]:%d, ", i, a[i]);
		printf("%d, ", a[i]);
	}
	printf("\n");

	merge_sort(sorted, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d, ", sorted[i]);
	printf("\n");

	index_unsorted(a, sorted, len);
	for (int i = 0; i < len; i++)
		printf("%d, ", a[i]);
	printf("\n");

	return (0);
}