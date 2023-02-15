/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:47:53 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/15 09:56:43 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void merge(int arr[], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int	buf[end + 1];

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
    while (i <= mid) {
        arr[k++] = buf[i++];
    }
    while (j <= end) {
        arr[k++] = buf[j++];
    }
}

void	merge_sort(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	int	mid = start + (end - start) / 2;

	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
