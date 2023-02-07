#include "p_swap.h"

void	nor(t_stack *st);
char	**parc(char **av, char **tmp, int ac);
void	atoi_str_to_stack(t_stack *st, char **av, int ac);
void	quit(t_stack *st, int ac, char **av);

int	main(int ac, char *av[])
{
	t_stack	st;
	char	**tmp;

	tmp = NULL;
	qu(ac);
	tmp = parc(av, tmp, &ac);
	if (check_arg(tmp) == 0)
		quit(&st, 1, tmp);
	atoi_str_to_stack(&st, tmp, ac++);
	if (check_repeat(st.tab_a, st.top_a) == 0)
		quit(&st, 1, 0);
	if (check_if_sorted(st.tab_a, st.top_a) == 0)
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

char	**parc(char **av, char **tmp, int ac)
{
	int		i;
	char	*tab;
	
	tab = NULL;
	if (check_space(av) == 0)
		quit(0, 5, 0);
	while (av[i])
	{
		tab = ft_strjoin(tab, av[i++]);
		tab = ft_strjoin(tab, " ");
	}
	tmp = ft_split(tab, ' ');
	i = 0;
	free(tab);
	if (!tmp)
		exit (0);
	while (tmp[i])
		i++;
	*ac = i;
	return (tmp);
}

void	atoi_str_to_stack(t_stack *st, char **av, int ac)
{
	long long	num;
	int			i;

	i = -1;
	st->top_b = -1;
	st->a = (int *)malloc(sizeof(int) * ac);
	st->b = (int *)malloc(sizeof(int) * ac);
	if (!st->a || !st->b)
		quit(st, 1, av);
	while (av[++i])
	{
		num = ft_atoi(av[i], st, av);
		if (num > 2147483647 || num < -2147483648)
			quit(st, 1, av);
		st->a[ac - i - 1] = (int)num;
	}
	st->top_a = i - 1;
}

void	quit(t_stack *st, int ac, char **av)
{
	if (ac == 1 || ac == 5)
		write(1, "Error\n", 6);
	if (ac != 2 && ac != 5)
	{
		free(st->a);
		free(st->b);
		if (av)
			free(av);
	}
	exit (0);
}
