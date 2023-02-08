#include "../includes/p_swap.h"

void	nor(t_stack *st);
char	**parc(char **av, char **tmp, int *ac);
void	atoi_str_to_stack(t_stack *st, char **av, int ac);
void	quit(t_stack *st, int ac, char **av);

int	main(int ac, char *av[])
{
	t_stack	st;
	char	**tmp;

	if (ac < 2)
		exit (0);
	printf("ac:'%d'\n", ac);
	//tmp = NULL;
	//tmp = parc(av, tmp, &ac);
	if (check_arg(ac, av) == 0)
		quit(&st, 1, tmp);
	printf("check ok!\n");
	atoi_str_to_stack(&st, av, ac - 1);
	printf("atio to stack ok!\n");
	if (check_repeat(st.a, st.top_a) == 0)
		quit(&st, 1, 0);
	printf("check rep OK!\n");
	// sorted needs to be fixed here. Program quits with err 0
	if (sorted(st.a, st.top_a) == 0)
		quit(&st, 0, 0);
	if (ac >= 3 && ac <= 6)
	{
		if (ac <= 4)
			sort_3nb(&st, ac);
		if (ac > 4)
			sort_5nb(&st, ac);
		quit(&st, 0, 0);
	}
	nor(&st);
	quit(&st, 2, tmp);
}

void	nor(t_stack *st)
{
	indexing(st);
	push_sorted_to_b(st);
	push_sorted_to_a(st);
}
/*
char	**parc(char **av, char **tmp, int *ac)
{
	int		i;
	char	*str_nb;
	
	printf("parc\n");
	str_nb = NULL;
	if (check_space(av) == 0)
		quit(0, 5, 0);
	i = 0;
	while (av[++i])
	{
		printf("\tav[%d]: '%s'\tstr: '%s'\n", i, av[i], str_nb);
		str_nb = ft_strjoin(str_nb, av[i]);
		str_nb = ft_strjoin(str_nb, " ");
	}
	printf("str: '%s'\n", str_nb);
	tmp = ft_split(str_nb, ' ');
	i = 0;
	free(str_nb);
	if (!tmp)
		exit (0);
	while (tmp[i])
		i++;
	*ac = i;
	return (tmp);
}
*/
void	atoi_str_to_stack(t_stack *st, char **av, int ac)
{
	long long	num;
	int			i;

	printf("atio to stack. ac'%d' .. av[1]:'%s'\n", ac, av[1]);
	i = 0;
	st->top_b = -1;
	st->a = (int *)malloc(sizeof(int) * ac);
	st->b = (int *)malloc(sizeof(int) * ac);
	if (!st->a || !st->b)
		quit(st, 1, av);
	while (av[++i])
	{
		printf("\tav[%d]: '%s'\t", i, av[i]);
		num = ft_atoi(av[i], st, av);
		if (num > 2147483647 || num < -2147483648)
			quit(st, 1, av);
		st->a[ac - i] = (int)num;
		printf("num:'%lld' > st->a[%d]:'%d'\n", num, ac - i, st->a[ac - i]);
	}
	st->top_a = ac;
	printf("st->top_a:'%d' i:'%d'\n", st->top_a, i);
}

void	quit(t_stack *st, int err, char **av)
{
	printf("quit err:'%d'\n", err);
	if (err == 1 || err == 5)
		write(1, "Error\n", 6);
	if (err != 2 && err != 5)
	{
		free(st->a);
		free(st->b);
		if (av)
			free(av);
	}
	exit (0);
}
