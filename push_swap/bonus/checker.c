/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/04 17:52:48 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/push_swap.h"
#include "../includes/checker.h"
#include "../includes/libft.h"

// get_stack
tstack	*get_stack(int size, char **av);
int	already_exists(int n, tstack *stack);
int	validate_int(char *elem);
int		fill_element(tstack *stack, char *arg);

// utils
void		reverse_array(int *arr, size_t size);
static void	_swap(int *a, int *b);
int		atoiv(const char *str, int *n);
int		is_sorted(tstack *stack);

// get_line instructions
int			get_instructions(char ***instructions);
static int	invalid_instruction(char *op);
static int	heap_set(char ***instructions, char **buffer, int i);

// execution inctructions
int			execute(char **instructions, tstack *a);
static void	swap_stacks(char *op, tstack *a, tstack *b);
static void	push_stacks(char *op, tstack *a, tstack *b);
static void	rotate_stacks(char *op, tstack *a, tstack *b);

// initialize
tstack	*initialize(unsigned int size);

// libstack
void	push(tstack *from, tstack *to);
void	swap(tstack *stack);
void	rotate(tstack *stack);
void	reverse_rotate(tstack *stack);

// free
void	free_array(void **arr);
void	free_stack(tstack *stack);
void	message_and_exit(tstack *stack, char **ops, int status);

/* libft
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_isspace(char str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_streq(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
*/
int	main(int ac, char **av)
{
	tstack	*st;
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

tstack	*get_stack(int size, char **av)
{
	unsigned int	i;
	int				status;
	tstack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(1024); // ok
	while (av[i] && !status)
		status = fill_element(stack, av[i++]); // ok
	if (status)
	{
		free_stack(stack); // ok
		ft_putendl_fd("Error", STDERR_FILENO); // ok
		exit(status);
	}
	reverse_array(stack->arr, stack->top + 1); // ok
	return (stack);
}

int	already_exists(int n, tstack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->arr[i] == n)
			return (1);
		i--;
	}
	return (0);
}

int	validate_int(char *elem)
{
	int			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = 1;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i])) // ok
			is_int = 0;
		i++;
	}
	return (!is_int);
}

// utils
void	reverse_array(int *arr, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		_swap(&arr[i++], &arr[size - 1]); // ok
		reverse_array(arr, size - 1); // ok
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

int	atoiv(const char *str, int *n)
{
	int		signal;
	int	overflow;

	*n = 0;
	signal = -1;
	overflow = 0;
	while (ft_isspace(*str)) // ok
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 - (*str++ - '0');
		if (*n > 0 || (*n == INT_MIN && signal < 0))
			overflow = 1;
	}
	*n *= signal;
	return (overflow);
}

int	is_sorted(tstack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->arr[i + 1] > stack->arr[i])
			return (0);
	}
	return (1);
}
// ***

int	fill_element(tstack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**arr;

	j = 0;
	status = 0;
	arr = ft_split(arg, ' '); // ok
	while (arr[j] && !status)
	{
		if (validate_int(arr[j])) // ok
			status = 1;
		if (atoiv(arr[j], &n)) // ok
			status = 2;
		if (already_exists(n, stack)) // ok
			status = 3;
		else
			stack->arr[++stack->top] = n;
		j++;
	}
	free_array((void **)arr); // ok
	return (status);
}

/*
** get_line instructions
*/
int	get_instructions(char ***instructions)
{
	int		i;
	int		status;
	char	*buffer[BUF_SIZE_INSTRUCTIONS];
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
			if (i == BUF_SIZE_INSTRUCTIONS)
			{
				heap_set(instructions, buffer, i); // ok
				ft_bzero(buffer, BUF_SIZE_INSTRUCTIONS); // ok
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i); // ok
	free(op);
	return (status);
}

static int	invalid_instruction(char *op)
{
	if (ft_streq(op, "sa")) // ok
		return (0);
	else if (ft_streq(op, "sb"))
		return (0);
	else if (ft_streq(op, "ss"))
		return (0);
	else if (ft_streq(op, "pa"))
		return (0);
	else if (ft_streq(op, "pb"))
		return (0);
	else if (ft_streq(op, "ra"))
		return (0);
	else if (ft_streq(op, "rb"))
		return (0);
	else if (ft_streq(op, "rr"))
		return (0);
	else if (ft_streq(op, "rra"))
		return (0);
	else if (ft_streq(op, "rrb"))
		return (0);
	else if (ft_streq(op, "rrr"))
		return (0);
	return (1);
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
int	execute(char **instructions, tstack *a)
{
	tstack	*b;

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

static void	swap_stacks(char *op, tstack *a, tstack *b)
{
	if (ft_streq(op, "sa") || ft_streq(op, "ss")) // ok
		swap(a); // ok
	if (ft_streq(op, "sb") || ft_streq(op, "ss"))
		swap(b);
}

static void	push_stacks(char *op, tstack *a, tstack *b)
{
	if (ft_streq(op, "pa"))
		push(b, a); // ok
	else if (ft_streq(op, "pb"))
		push(a, b);
}

static void	rotate_stacks(char *op, tstack *a, tstack *b)
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
tstack	*initialize(unsigned int size)
{
	tstack	*stack;

	stack = malloc(sizeof(*stack));
	if (!(stack))
		return (NULL);
	stack->arr = malloc(size * sizeof(*(stack->arr)));
	if (!(stack->arr))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

/*
** libstack
*/

void	push(tstack *from, tstack *to)
{
	if (from->top == -1)
		return ;
	to->arr[++to->top] = from->arr[from->top--];
}

void	swap(tstack *stack)
{
	int	aux;

	if (stack->top <= 0)
		return ;
	aux = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = aux;
}

void	rotate(tstack *stack)
{
	unsigned int	i;
	int				tmp;

	i = stack->top + 1;
	tmp = stack->arr[stack->top];
	while (--i)
		stack->arr[i] = stack->arr[i - 1];
	stack->arr[0] = tmp;
}

void	reverse_rotate(tstack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->arr[0];
	while (++i < stack->top)
		stack->arr[i] = stack->arr[i + 1];
	stack->arr[stack->top] = tmp;
}

/*
** free
*/
void	free_array(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_stack(tstack *stack)
{
	free(stack->arr);
	free(stack);
}

void	message_and_exit(tstack *stack, char **ops, int status)
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

int	ft_streq(const char *s1, const char *s2)
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

*/