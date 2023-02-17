/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rand_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:03:08 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/17 17:30:51 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	get_rand_nums(int *a, int len, int min, int max);
static void	get_new_random(int *num, int *min, int *max);
void	print_random(int *arr, int len);

int	main()
{
	int	len = 100;
	int	min = -500;
	int	max = 500;
	//int	min = -214748364;
	//int	max = 2147483647;
	int	arr[len];

	get_rand_nums(arr, len, min, max);
	print_random(arr, len);
	return (0);
}

void	get_rand_nums(int *a, int len, int min, int max)
{
	int	new_random;

	srand(time(NULL) * getpid());

	for (int i = 0; i < len; i++)
	{
		get_new_random(&new_random, &min, &max);
		for (int j = 0; j <= i; j++)
		{
			if (a[j] == new_random)
			{
				get_new_random(&new_random, &min, &max);
				j = 0;
			}
		}
		a[i] = new_random;
	}
}

static void	get_new_random(int *num, int *min, int *max)
{
	*num = (rand() % (*max - *min + 1)) + *min;
}

void	print_random(int *arr, int len)
{
	int i = -1;

	while (++i < len)
		printf("%d ", arr[i]);
	printf("\n");
}
