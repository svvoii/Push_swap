/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/01/28 15:42:08 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main()
{
	int	len = 100;
	int	min = 0;
	int	max = 999;
	int	a[len];

	get_rand_nums(a, len, min, max);
	
	for (int i = 0; i < len; i++)
		printf("%d, ", a[i]);
	printf("\n");

	return (0);
}