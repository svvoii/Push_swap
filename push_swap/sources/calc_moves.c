/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/25 13:58:49 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
int	case_ra_rb(t_stack *st, int item);
int	case_rra_rrb(t_stack *st, int item);
int	case_rra_rb(t_stack *st, int item);
int	case_ra_rrb(t_stack *st, int item);
int	ra_rb(t_stack *st, int item);
int	ra_rrb(t_stack *st, int item);
int	rra_rrb(t_stack *st, int item);
int	rra_rb(t_stack *st, int item);

int	case_ra_rb(t_stack *st, int item)
{
	int	i;

	i = find_place_to_insert_b(st, item);
	if (i < find_index(st, 'a', item))
		i = find_index(st, 'a', item);
	//printf("\t\tcase ra_rb \ti:'%d'\n",  i);
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
	//printf("\t\tcase rra_rrb \ti:'%d'\n",  i);
	return (i);
}

int	case_rra_rb(t_stack *st, int item)
{
	int	i;

	i = 0;
	if (find_index(st, 'a', item))
		i = st->size_a - find_index(st, 'a', item);
	i += find_place_to_insert_b(st, item);
	//printf("\t\tcase rra_rb \ti:'%d'\n",  i);
	return (i);
}

int	case_ra_rrb(t_stack *st, int item)
{
	int	i;

	i = 0;
	if (find_place_to_insert_b(st, item))
		i = st->size_b - find_place_to_insert_b(st, item);
	i += find_index(st, 'a', item);
	//printf("\t\tcase ra_rrb \ti:'%d'\n",  i);
	return (i);
}

int	ra_rb(t_stack *st, int item)
{
	int	top;

	top = st->size_a - 1;
	while (st->a[top] != item && find_place_to_insert_b(st, item) > 0)
	{
		printf("\t\trr ra_rrb a[%d]:'%d' != '%d'\n", top, st->a[top], item);
		rotate(st, 'r');
	}
	while (st->a[top] != item)
	{
		printf("\t\tra ra_rrb a[%d]:'%d' != '%d'\n", top, st->a[top], item);
		rotate(st, 'a');
	}
	while (find_place_to_insert_b(st, item) > 0)
	{
		printf("\t\trb ra_rrb b[%d]:'%d' != '%d'\n", st->size_b - 1, st->b[st->size_b - 1], item);
		rotate(st, 'b');
	}
	return (-1);
}

int	ra_rrb(t_stack *st, int item)
{
	int	top;

	top = st->size_a - 1;
	while (st->a[top] != item)
		rotate(st, 'a');
	while (find_place_to_insert_b(st, item) > 0)
		reverse_rotate(st, 'b');
	return (-1);
}

int	rra_rrb(t_stack *st, int item)
{
	int	top;

	top = st->size_a - 1;
	while (st->a[top] != item && find_place_to_insert_b(st, item) > 0)
		reverse_rotate(st, 'r');
	while (st->a[top] != item)
		reverse_rotate(st, 'a');
	while (find_place_to_insert_b(st, item) > 0)
		reverse_rotate(st, 'b');
	return (-1);
}

int	rra_rb(t_stack *st, int item)
{
	int	top;

	top = st->size_a - 1;
	while (st->a[top] != item)
		reverse_rotate(st, 'a');
	while (find_place_to_insert_b(st, item) > 0)
		rotate(st, 'b');
	return (-1);
}
*/
