/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/03 10:28:23 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int	main(int ac, char **av)
{
	t_stack	*st;
	int		status;
	char	**instructions;

	status = 0;
	instructions = NULL;
	st = get_stack(ac - 1, &av[1]); // ok
	status = get_instructions(&instructions); // ok
	if (status)
		message_and_exit(st, instructions, status); // ok
	execute(instructions, st); // ok
	free_array((void **)instructions); // ok
	free_stack(st); // ok
	return (status);
}

/*
** get_stack
*/

t_stack	*get_stack(int size, char **av)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(STACK_BUFFER); // ok
	while (av[i] && !status)
		status = fill_element(stack, av[i++]); // ok
	if (status)
	{
		free_stack(stack); // ok
		ft_putendl_fd("Error", STDERR_FILENO); // ok
		exit(status);
	}
	reverse_array(stack->array, stack->top + 1); // ok
	return (stack);
}

bool	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == n)
			return (true);
		i--;
	}
	return (false);
}

bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i])) // ok
			is_int = false;
		i++;
	}
	return (!is_int);
}

// utils
void	reverse_array(int *array, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		_swap(&array[i++], &array[size - 1]); // ok
		reverse_array(array, size - 1); // ok
	}
	i = 0;
}

static void	_swap(int *a, int *b)
{
	int	aux;

	aux = *b;
	*b = *a;
	*a = aux;
}

bool	atoiv(const char *str, int *n)
{
	int		signal;
	bool	overflow;

	*n = 0;
	signal = -1;
	overflow = false;
	while (ft_isspace(*str)) // ok
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 - (*str++ - '0');
		if (*n > 0 || (*n == INT_MIN && signal < 0))
			overflow = true;
	}
	*n *= signal;
	return (overflow);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->array[i + 1] > stack->array[i])
			return (false);
	}
	return (true);
}
// ***

int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE); // ok
	while (array[j] && !status)
	{
		if (validate_int(array[j])) // ok
			status = 1;
		if (atoiv(array[j], &n)) // ok
			status = 2;
		if (already_exists(n, stack)) // ok
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array); // ok
	return (status);
}

/*
** get_line instructions
*/
int	get_instructions(char ***instructions)
{
	int		i;
	int		status;
	char	*buffer[INSTRUCTIONS_BUFFER_SIZE];
	char	*op;

	i = 0;
	status = 0;
	while (!status && (get_next_line(STDIN_FILENO, &op) > 0)) // ok
	{
		if (invalid_instruction(op)) // ok
			status = 1;
		else
		{
			buffer[i++] = op;
			if (i == INSTRUCTIONS_BUFFER_SIZE)
			{
				heap_set(instructions, buffer, i); // ok
				ft_bzero(buffer, INSTRUCTIONS_BUFFER_SIZE); // ok
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i); // ok
	free(op);
	return (status);
}

static bool	invalid_instruction(char *op)
{
	if (ft_streq(op, "sa")) // ok
		return (false);
	else if (ft_streq(op, "sb"))
		return (false);
	else if (ft_streq(op, "ss"))
		return (false);
	else if (ft_streq(op, "pa"))
		return (false);
	else if (ft_streq(op, "pb"))
		return (false);
	else if (ft_streq(op, "ra"))
		return (false);
	else if (ft_streq(op, "rb"))
		return (false);
	else if (ft_streq(op, "rr"))
		return (false);
	else if (ft_streq(op, "rra"))
		return (false);
	else if (ft_streq(op, "rrb"))
		return (false);
	else if (ft_streq(op, "rrr"))
		return (false);
	return (true);
}

static int	heap_set(char ***instructions, char **buffer, int i)
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

/*
** execution inctructions
*/
int	execute(char **instructions, t_stack *a)
{
	t_stack	*b;

	b = initialize(a->size); // ok
	while (*instructions)
	{
		if (*instructions[0] == 's')
			swap_stacks(*instructions, a, b); // ok
		else if (*instructions[0] == 'p')
			push_stacks(*instructions, a, b); // ok
		else
			rotate_stacks(*instructions, a, b); // ok
		instructions++;
	}
	if (!is_sorted(a) || b->top > -1) // ok
		ft_putstr_fd("KO\n", STDOUT_FILENO); // ok
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	free_stack(b); // ok
	return (0);
}

static void	swap_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, "sa") || ft_streq(op, "ss")) // ok
		swap(a); // ok
	if (ft_streq(op, "sb") || ft_streq(op, "ss"))
		swap(b);
}

static void	push_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, "pa"))
		push(b, a); // ok
	else if (ft_streq(op, "pb"))
		push(a, b);
}

static void	rotate_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, "ra") || ft_streq(op, "rr"))
		rotate(a); // ok
	if (ft_streq(op, "rb") || ft_streq(op, "rr"))
		rotate(b);
	if (ft_streq(op, "rra") || ft_streq(op, "rrr"))
		reverse_rotate(a); // ok
	if (ft_streq(op, "rrb") || ft_streq(op, "rrr"))
		reverse_rotate(b);
}

/*
** initialize
*/
t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!(stack))
		return (NULL);
	stack->array = malloc(size * sizeof(*(stack->array)));
	if (!(stack->array))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

/*
** libstack
*/

void	push(t_stack *from, t_stack *to)
{
	if (from->top == -1)
		return ;
	to->array[++to->top] = from->array[from->top--];
}

void	swap(t_stack *stack)
{
	int	aux;

	if (stack->top <= 0)
		return ;
	aux = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = aux;
}

void	rotate(t_stack *stack)
{
	unsigned int	i;
	int				tmp;

	i = stack->top + 1;
	tmp = stack->array[stack->top];
	while (--i)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->array[0];
	while (++i < stack->top)
		stack->array[i] = stack->array[i + 1];
	stack->array[stack->top] = tmp;
}

/*
** free
*/
void	free_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	message_and_exit(t_stack *stack, char **ops, int status)
{
	if (stack)
		free_stack(stack);
	if (ops)
		free_array((void **)ops);
	ft_putstr_fd("Error\n", STDERR_FILENO); // ok
	exit(status);
}

/*
** libft
*/

void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	if (*s)
	{
		ft_putchar_fd(*s, fd);
		ft_putstr_fd(++s, fd);
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char str)
{
	return (str == 0x20 || (str >= 0x09 && str <= 0x0d));
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

bool	ft_streq(const char *s1, const char *s2)
{
	return (!(ft_strncmp(s1, s2, ft_strlen(s2) + 1)));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	else if ((*s1 != *s2) || !*s1)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strncmp(++s1, ++s2, --n));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n-- && dst != src)
		*d++ = *s++;
	return (dst);
}
