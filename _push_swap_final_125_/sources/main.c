/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 11:28:23 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	t_stack	*st;
	int		count;

	st = &stack;
	if (ac < 2)
		exit (0);
	st->input_str = copy_to_2d_str_arr(ac, av, &count);
	create_stacks_a_b(st, count);
	atoi_str_to_stack(st, ac);
	if (!unique_values(st))
		free_and_quit(st, ac, 1);
	if (sorted(st))
		free_and_quit(st, ac, 0);
	indexing(st);
	push_chunks_to_b(st);
	smart_push_back_to_a(st);
	free_and_quit(st, ac, 0);
	return (0);
}
