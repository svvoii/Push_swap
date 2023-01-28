/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:12 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/27 14:28:15 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void	combine(int a[], int start, int mid, int end) {
	int	*buf = new int [end + 1];
	int	i = start;
	int	j, k;

	while (i <= end) {
		buf[i] = a[i];
		i++;
	}
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end) {
		if (buf[i] <= buf[j]) {
			a[k] = buf[i];
			i++;
		}
		else {
			a[k] = buf[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		a[k] = buf[i];
		i++;
		k++;
	}	
	while (j <= end) {
		a[k] = buf[j];
		j++;
		k++;
	}
	delete[] buf;
}

// Auxiliary function (helper function)
void	merge_sort(int a[], int start, int end) {
	if (start >= end)
		return ;
	int	mid = start + (end - start) / 2;
	//int mid = (start + end) / 2;
	merge_sort(a, start, mid);
	merge_sort(a, mid + 1, end);
	combine(a, start, mid, end);
}

// Wrapper function
void	merge_sort(int a[], int size) {
	merge_sort(a, 0, size - 1);
}

void	display(int	a[], int size) {
	int	i = -1;

	while (++i < size)
		cout << a[i] << ", ";
	cout << endl;
}

int	main() {
	int	arr[] = {43, 245, 12, 132, 87, 42, 12, 167, 462, 89, 43};
	int	size = sizeof(arr) / sizeof(arr[0]);

	display(arr, size);
	merge_sort(arr, size);
	display(arr, size);

	return (0);
}
