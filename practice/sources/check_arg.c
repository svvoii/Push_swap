#include "p_swap.h"

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av || !*av)
		return (0);
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || v[i][j] == '+'))
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_repeat(int *st, int top)
{
	int	i;
	int	j;

	i = -1;
	while (++i < top)
	{
		j = i;
		while (++j <= top)
		{
			if (st[i] == st[j])
				return (0);
		}
	}
	return (1);
}

int	check_space(char **av)
{
	int	i;
	int j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == ' ' && j == 0)
				return (0);
			if (av[i][j] == ' ' && (av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				return (0);
		}
	}
	return (1);
}
