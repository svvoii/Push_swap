/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:47:53 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/28 16:30:26 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_rest(int arr[], int start, int mid, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i <= (mid - start))
	{
		sorted[i] = arr[start + i];
		i++;
	}
	j = 0;
	while (j < (end - mid))
	{
		sorted[mid + j] = arr[mid + 1 + j];
		j++;
	}
}

void merge(int arr[], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int	sorted[end - start];
	int	left[mid - start + 1];
	int	right[end - mid];

	i = 0;
	j = 0;
	k = start;
	while (i < (mid - start + 1) && j < (end - mid))
	{
		if (left[i] <= right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		k++;
	}
	fill_rest(arr, &i, &j, &k);	
}

void	merge_sort(int *arr, int start, int end)
{
	if (start < end)
	{
		int	mid = start + (end - start) / 2;

		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}