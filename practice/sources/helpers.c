#include "../includes/p_swap.h"

// Return 0 if unsorted and 1 is stack is sorted
int	sorted(t_stack *stack)
{
	int i;
	int	j;
	int	size;

	//printf("sorted..\t");
	size = stack->size_a;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j <= size)
			if (stack->a[i] < stack->a[j])
			{
				//printf("return 0 unsorted\t");
				return (0);
			}
	}
	//printf("return 1 sorted\t");
	return (1);
}

long long	ft_atoi(char *str, t_stack *stack)
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
			quit(stack, 1);
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
