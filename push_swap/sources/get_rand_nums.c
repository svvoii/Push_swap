/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_rand_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:03:08 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/28 15:35:47 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_new_random(int *num, int *min, int *max)
{
	*num = (rand() % (*max - *min + 1)) + *min;
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
