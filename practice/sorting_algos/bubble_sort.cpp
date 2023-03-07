/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:14:51 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/24 15:31:20 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void	swap(int a[], int x, int y) {
	int	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void	bubble(int a[], int n) {
	int	i = n;

	while (--i > 0) {
		if (a[i] < a[i - 1]) {
			swap(a, i, i - 1);
		}
	}
}

void	bubble_sort(int a[], int n) {
	int	i = -1;

	while (++i < n - 1) {
		bubble(a, n);
	}
}

void	display(int a[], int size) {
	int	i = -1;

	while (++i < size)
		cout << a[i] << ", ";
	cout << endl;
}

int	main() {
	int	arr[] = {102, 298, 254, 43, 84, 96, 34, 42, 11, 55};
	int	size = sizeof(arr)/sizeof(arr[0]);

	display(arr, size);
	bubble_sort(arr, size);
	display(arr, size);

	return (0);
}