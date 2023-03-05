/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:47:53 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/05 11:45:31 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		execute(t_stack *st, char **instructions);
void	swap_stacks(t_stack *st, char *operation);
void	push_stacks(t_stack *st, char *op);
void	rotate_stacks(t_stack *st, char *op);

int	execute(t_stack *st, char **instructions)
{
	while (*instructions)
	{
		if (*instructions[0] == 's')
			swap_stacks(st, *instructions);
		else if (*instructions[0] == 'p')
			push_stacks(st, *instructions);
		else
			rotate_stacks(st, *instructions);
		instructions++;
	}
	if (!sorted(st) || st->size_b != 0)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	return (0);
}

void	swap_stacks(t_stack *st, char *operation)
{
	if (ft_streq(operation, "sa") || ft_streq(operation, "ss"))
	 	swap(st, 'a', 0);
	if (ft_streq(operation, "sb") || ft_streq(operation, "ss"))
	 	swap(st, 'b', 0);
}

void	push_stacks(t_stack *st, char *op)
{
	int	item;

	if (ft_streq(op, "pa"))
	{
		pop(&item, st, 'b');
		push(item, st, 'a', 0);
	}
	else if (ft_streq(op, "pb"))
	{
		pop(&item, st, 'a');
		push(item, st, 'b', 0);
	}
}

void	rotate_stacks(t_stack *st, char *op)
{
	if (ft_streq(op, "ra"))
	 	rotate(st, 'a', 0);
	if (ft_streq(op, "rb"))
	 	rotate(st, 'b', 0);
	if (ft_streq(op, "rr"))
	 	rotate(st, 'r', 0);
	if (ft_streq(op, "rra"))
	 	reverse_rotate(st, 'a', 0);
	if (ft_streq(op, "rrb"))
	 	reverse_rotate(st, 'b', 0);
	if (ft_streq(op, "rrr"))
	 	reverse_rotate(st, 'r', 0);
}
