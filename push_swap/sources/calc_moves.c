/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/22 17:44:41 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	case_ra_rb(t_stack *st, int item)
{
	int	i;

	i = find_place_to_insert_b(st, item);
	if (i < find_index(st, 'a', item))
		i = find_index(st, 'a', item);
	return (i);
}

int	case_rra_rrb(t_stack *st, int item)
{
	int i;

	i = 0;
	if (find_place_to_insert_b(st, item))
		i = st->size_b - find_place_to_insert_b(st, item);
	if ((i < (st->size_a - find_index(st, 'a', item))) && find_index(st, 'a', item))
		i = st->size_a - find_index(st, 'a', item);
	return (i);
}

int	case_rra_rb(t_stack *st, int item)
{
	int	i;

	i = 0;
	if (find_index(st, 'a', item))
		i = st->size_a - find_index(st, 'a', item);
	i += find_place_to_insert_b(st, item);
	return (i);
}

int	case_rra_rb(t_stack *st, int item)
{
	int	i;

	i = 0;
	if (find_place_to_insert_b(st, item))
		i = st->size_b - find_place_to_insert_b(st, item);
	i += find_index(st, 'a', item);
	return (i);
}
