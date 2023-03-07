/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:41:53 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/24 15:13:35 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

// SELECTION SORT

void	swap(int a[], int x, int y) {
	int	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

int	locate_smallest(int	a[], int i, int end) {
	int	j = i;

	while (++i <= end) {
		if (a[i] < a[j])
			j = i;
	}
	return (j);
}

void	selection_sort(int a[], int n) {
	int	i = 0;
	int	j = 0;

	while (i < n - 1) {
		j = locate_smallest(a, i, n - 1);
		swap(a, i, j);
		i++;
	}
}

void	display(int a[], int n) {
	int	i = -1;

	while (++i < n)
		cout << a[i] << ", ";
	cout << endl;
}

int main()
{
	int	arr[] = {102, 42, 12, 193, 11, 190, 39, 192, 239};
	int size = sizeof(arr)/sizeof(int);

	display(arr, size);
	selection_sort(arr, size);
	display(arr, size);

	return (0);
}