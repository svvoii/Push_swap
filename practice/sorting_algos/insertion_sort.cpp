/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:36:38 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/24 15:53:52 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void	insert_i(int a[], int i) {
	int	key = a[i];
	int	j = i;

	while (--j >= 0 && a[j] > key) {
		a[j + 1] = a[j];
	}
	a[j + 1] = key;
}

void	insertion_sort(int a[], int size) {
	int	i = 0;

	while (++i < size) {
		insert_i(a, i);
	}
}

void	display(int a[], int size) {
	int i = -1;

	while (++i < size)
		cout << a[i] << ", ";
	cout << endl;
}

int	main() {
	int	arr[] = {102, 435, 56, 98, 754, 42, 10, 76, 96, 90, 53, 42, 11};
	int	size = sizeof(arr) / sizeof(arr[0]);

	display(arr, size);
	insertion_sort(arr, size);
	display(arr, size);

	return (0);
}