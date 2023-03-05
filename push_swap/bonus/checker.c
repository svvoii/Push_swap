/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/05 11:49:26 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		get_instructions(char ***instructions, int *err);
int		invalid_instruction(char *operation);
int		heap_set(char ***instructions, char **buffer, int i);
void	message_and_exit(t_stack *st, char **ops, int ac, int err);

int	main(int ac, char **av)
{
	t_stack		stack;
	t_stack		*st;
	char		**instructions;
	int			count;
	int			err;

	st = &stack;
	if (ac < 2)
		exit (0);
	st->input_str = copy_to_2d_str_arr(ac, av, &count);
	create_stacks_a_b(st, count);
	atoi_str_to_stack(st->input_str, st, ac);
	get_instructions(&instructions, &err);	
	if (err)
		message_and_exit(st, instructions, ac, err);
	execute(st, instructions);
	message_and_exit(st, instructions, ac, err);
}

int	get_instructions(char ***instructions, int *err)
{
	int		i;
	char	*buffer[4096];
	char	*operation;

	*err = 0;
	i = 0;
	while (!*err && (get_next_line(STDIN_FILENO, &operation) > 0))
	{
		if (invalid_instruction(operation))
			*err = 1;
		else
		{
			buffer[i++] = operation;
			if (i == 4096)
			{
				heap_set(instructions, buffer, i);
				ft_bzero(buffer, 4096);
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i);
	free(operation);
}

int	invalid_instruction(char *operation)
{
	if (ft_streq(operation, "sa"))
		return (0);
	else if (ft_streq(operation, "sb"))
		return (0);
	else if (ft_streq(operation, "ss"))
		return (0);
	else if (ft_streq(operation, "pa"))
		return (0);
	else if (ft_streq(operation, "pb"))
		return (0);
	else if (ft_streq(operation, "ra"))
		return (0);
	else if (ft_streq(operation, "rb"))
		return (0);
	else if (ft_streq(operation, "rr"))
		return (0);
	else if (ft_streq(operation, "rra"))
		return (0);
	else if (ft_streq(operation, "rrb"))
		return (0);
	else if (ft_streq(operation, "rrr"))
		return (0);
	return (1);
}

int	heap_set(char ***instructions, char **buffer, int i)
{
	char			**tmp;
	static size_t	in_size;

	tmp = malloc((in_size + i + 1) * sizeof(*tmp));
	if (!tmp)
		return (1);
	if (in_size)
	{
		ft_memcpy(tmp, *instructions, in_size * sizeof(*tmp)); // ok
		free(*instructions);
	}
	ft_memcpy(tmp + in_size, buffer, i * sizeof(*tmp));
	tmp[in_size + i] = NULL;
	in_size += i;
	*instructions = tmp;
	return (0);
}

void	message_and_exit(t_stack *st, char **ops, int ac, int err)
{
	unsigned int	i;

	if (ops)
	{
		i = 0;
		while (ops[i])
			free(ops[i++]);
		free(ops);
	}
	free_and_quit(st, ac, err);
}
