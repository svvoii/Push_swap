/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:24 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/03 19:17:26 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Put the new item to the top of the stack (adds item to the end ofthe array)
int	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return (0);
	stack->collection[stack->size] = item;
	stack->size++;
	return (1);
	printf("pb\n");
}

// Decreases the size ofthe array by 1
int	pop(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	stack->size--;
	*item = stack->collection[stack->size];
	return (1);
}

// Retrieves the top item from the stack (the last item of the array, size - 1)
int	peek(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	*item = stack->collection[stack->size - 1];
	return (1);
}

// Moves the top item to bottom of stack (the last array item put at index 0)
void	rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	tmp = arr[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		arr[i + 1] = arr[i];
		i--;
	}
	arr[0] = tmp;
	printf("ra\n");
}

// The bottom stack value moved to the top (last array item appears at 0 index)
void	reverse_rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	tmp = arr[0];
	i = 0;
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len - 1] = tmp;
	printf("rra\n");
}
