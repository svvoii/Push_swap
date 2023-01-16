/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:09:17 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/16 16:37:12 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

int	main()
{
	int	n;
	int	arr[MAX];

	cout << "Enter num N: " << endl;
	cin >> n;

	// inputing values into array

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

	// output unsorted array

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	// Sorting array, ascending order

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int	tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return (0);
}