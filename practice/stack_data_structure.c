/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:23:11 by sbocanci          #+#    #+#             */
/*   Updated: 2023/02/01 16:40:20 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}	t_stack;

t_stack	*create_stack(int capacity);
void	destroy_stack(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		pop(t_stack *stack, int *item);
int		push(t_stack *stack, int item);
int		peek(t_stack *stack, int *item);
void	rotate(int *arr, int len);
void	reverse_rotate(int *arr, int len);

int	main(void)
{
	t_stack	*stack;
	int		peek_val;
	int		pop_val;

	stack = create_stack(5);
	if (!stack)
	{
		printf("error creating stack.\n");
		return (1);
	}
	push(stack, 9);
	push(stack, 42);
	push(stack, 1);
	push(stack, 33);
	push(stack, 7);
	if (is_full(stack))
		printf("stack is full.\n");
	printf("stack size: '%d'\n", stack->size);
	peek_val = 0;
	peek(stack, &peek_val);
	printf("peek val:'%d'\n", peek_val);
	for (int i = 0; i < stack->size; i++)
		printf("\ta[%d]: '%d'\n", i, stack->collection[i]);
	reverse_rotate(stack->collection, stack->size);
	printf("after roation:\n");
	for (int i = 0; i < stack->size; i++)
		printf("\ta[%d]: '%d'\n", i, stack->collection[i]);
	peek(stack, &peek_val);
	printf("peek val:'%d'\n", peek_val);
	/*
	while (!is_empty(stack))
	{
		pop(stack, &pop_val);
		printf("pop value:'%d'\n", pop_val);
	}
	*/
	if (is_empty(stack))
		printf("stack is empty.\n");
	destroy_stack(stack);
	return (0);
}

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	if (capacity <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->collection = malloc(sizeof(int) * capacity);
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->collection);
	free(stack);
}

int	is_full(t_stack *stack)
{
	return (stack->capacity == stack->size);
}

int	is_empty(t_stack *stack)
{
	return (stack-> size == 0);
}

int	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return (0);
	stack->collection[stack->size] = item;
	stack->size++;
	return (1);
}

int	pop(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	stack->size--;
	*item = stack->collection[stack->size];
	return (1);
}

int	peek(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (0);
	*item = stack->collection[stack->size - 1];
	return (1);
}

// The top value goes to the very bottom
void	rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	tmp = arr[len - 1];
	i = len - 1;
	while (--i >= 0)
		arr[i + 1] = arr[i];
	arr[0] = tmp;
}

// The bottom value goes to the top
void	reverse_rotate(int *arr, int len)
{
	int	tmp;
	int	i;

	tmp = arr[0];
	i = -1;
	while (++i < len - 1)
		arr[i] = arr[i + 1];
	arr[len - 1] = tmp;
}
