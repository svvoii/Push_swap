#include "../includes/p_swap.h"

int	check_space(char **av);
int	unique_values(int *st, int size);
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
		//printf("\tav[%d]:'%s'\n", i, av[i]);
	}
	return (1);
}

int	unique_values(int *st, int size)
{
	int	i;
	int	j;

	//printf("check repeat..\t");
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			//printf("st[%d]:'%d' == ", i, st[i]);
			//printf("st[%d]:'%d'\n", j, st[j]);
			if (st[i] == st[j])
				return (0);
		}
	}
	//printf("size:'%d' > return (1)\t", size);
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

/*
int	valid_argv(int count, char **str)
{
	int	i;
	int	j;

	if (!str || !*str)
		return (0);
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (str[i][++j])
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if ((str[i][j] < '0' || str[i][j] > '9'))
				return (0);
		}
	}
	return (1);
}
*/