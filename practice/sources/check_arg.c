#include "../includes/p_swap.h"

int	check_space(char **av);
int	check_repeat(int *st, int top);
int	check_arg(int ac, char **av);

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	if (!av || !*av)
		return (0);
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (0);
		}
		printf("\tav[%d]:'%s'\n", i, av[i]);
	}
	return (1);
}

int	check_repeat(int *st, int top)
{
	int	i;
	int	j;

	printf("check repeat..\t");
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
