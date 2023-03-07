/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_psw_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 12:31:27 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		abs(int n);
void	spin(t_stack *st, int *ra, int *rb, int i);
void	rr_ra_rb(t_stack *st, int a, int b);
void	rrr_rra_rrb(t_stack *st, int a, int b);
void	bring_min_to_top(t_stack *st);

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	spin(t_stack *st, int *ra, int *rb, int i)
{
	if (ra[i] >= 0 && rb[i] >= 0)
		rr_ra_rb(st, ra[i], rb[i]);
	else if (ra[i] < 0 && rb[i] < 0)
		rrr_rra_rrb(st, abs(ra[i]), abs(rb[i]));
	else
	{
		if (ra[i] >= 0 && rb[i] < 0)
		{
			rr_ra_rb(st, ra[i], 0);
			rrr_rra_rrb(st, 0, abs(rb[i]));
		}
		if (ra[i] < 0 && rb[i] >= 0)
		{
			rrr_rra_rrb(st, abs(ra[i]), 0);
			rr_ra_rb(st, 0, rb[i]);
		}
	}
}

void	rr_ra_rb(t_stack *st, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rotate(st, 'r', 1);
		a--;
		b--;
	}
	while (a-- > 0)
		rotate(st, 'a', 1);
	while (b-- > 0)
		rotate(st, 'b', 1);
}

void	rrr_rra_rrb(t_stack *st, int a, int b)
{
	while (a > 0 && b > 0)
	{
		reverse_rotate(st, 'r', 1);
		a--;
		b--;
	}
	while (a-- > 0)
		reverse_rotate(st, 'a', 1);
	while (b-- > 0)
		reverse_rotate(st, 'b', 1);
}

void	bring_min_to_top(t_stack *st)
{
	int	i;

	i = min_index(st->a, st->size_a);
	if (i <= st->size_a / 2)
		while (i-- > 0)
			rotate(st, 'a', 1);
	else
	{
		i = st->size_a - i;
		while (i-- > 0)
			reverse_rotate(st, 'a', 1);
	}
}
