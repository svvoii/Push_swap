/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/06 14:21:28 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft.h"

# define GNL_BUF_SIZE	1024

/* checker.c */
int		get_next_line(int fd, char **line);
void	get_instructions(char ***instructions, int *err);
int		invalid_instruction(char *operation);
int		heap_set(char ***instructions, char **buffer, int i);
void	message_and_exit(t_stack *st, char **ops, int ac, int err);
/* execute.c */
int		execute(t_stack *st, char **instructions);
void	swap_stacks(t_stack *st, char *operation);
void	push_stacks(t_stack *st, char *op);
void	rotate_stacks(t_stack *st, char *op);

#endif
