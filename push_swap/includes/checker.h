/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/05 11:51:09 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../libft/libft.h"

# define GNL_BUF_SIZE	1024
//# define BUF_SIZE		4096

/* checker.c */
int		get_next_line(int fd, char **line);
int		get_instructions(char ***instructions, int *err);
int		invalid_instruction(char *operation);
int		heap_set(char ***instructions, char **buffer, int i);
void	message_and_exit(t_stack *st, char **ops, int ac, int err);
/* execute.c */
int		execute(t_stack *st, char **instructions);
void	swap_stacks(t_stack *st, char *operation);
void	push_stacks(t_stack *st, char *op);
void	rotate_stacks(t_stack *st, char *op);

#endif
