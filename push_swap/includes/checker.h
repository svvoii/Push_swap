/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/04 17:41:45 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//# include "push_swap.h"
# include "libft.h"

# define OPEN_MAX				16
# define BUFFER_SIZE			1024
# define BUF_SIZE_INSTRUCTIONS	4096

typedef struct stack
{
	int				top;
	unsigned int	size;
	int				*arr;
}	tstack;

int		get_next_line(int fd, char **line);

#endif
