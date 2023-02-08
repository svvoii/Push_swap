#include "../includes/p_swap.h"

int	find_j(int *stack, int top, int j)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (j == stack[i])
			return (i);
		i++;
	}
	return (-1);
}

int	sorted(int *stack, int top)
{
	int i;
	int	j;

	i = -1;
	while (++i < top)
	{
		j = i;
		while (++j <= top)
			if (stack[i] < stack[j])
				return (1);
	}
	return (0);
}

long long	ft_atoi(char *str, t_stack *stack, char **av)
{
	int			i;
	long long	r;
	long long	sign;

	i = 0;
	r = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			quit(stack, 1, av);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + ((long long)str[i] - '0');
		i++;
	}
	return (r * sign);
}
