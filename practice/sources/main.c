#include "../includes/p_swap.h"

void	atoi_str_to_stack(t_stack *st, char **av, int ac);
void	quit(t_stack *st, int ac);

int	main(int ac, char *av[])
{
	t_stack	st;
	char	**tmp;

	if (ac < 2)
		exit (0);
	//printf("ac:'%d'\n", ac);
	//tmp = NULL;
	//tmp = parc(av, tmp, &ac);
	if (check_arg(ac, av) == 0)
		quit(&st, 1);
	//printf("check ok!\n");
	atoi_str_to_stack(&st, av, ac);
	//printf("atoi to stack ok!\n");
	if (!unique_values(st.a, st.size_a))
		quit(&st, 1);
	//printf("..check rep OK!\n");
	// sorted needs to be fixed here. Program quits with err 0
	//printf("check sort..\t");
	if (sorted(&st))
	{
		//printf(" sorted ");
		quit(&st, 0);
	}
	//printf("..end check sort\n");
	//printf("ac:'%d'\n", ac);
	if (ac >= 3 && ac <= 6)
	{
		//printf("\tac >= 3 && ac <= 6\n");
		if (ac <= 4)
			sort_3nb(&st, ac - 1);
		if (ac > 4)
			sort_5nb(&st, ac - 1);
		quit(&st, 0);
	}
	indexing(&st);
	first_push_to_b(&st);
	pushback_to_a(&st);
	quit(&st, 2);
}
/*
	printf("\na:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\nb:\t");
	for (int i = 0; i < st->size_b; i++)
		printf("%d, ", st->b[i]);
	printf("\n");


	printf("\na:\t");
	for (int i = 0; i < st->size_a; i++)
		printf("%d, ", st->a[i]);
	printf("\nb:\t");
	for (int i = 0; i < st->size_b; i++)
		printf("%d, ", st->b[i]);
	printf("\n");
*/

void	atoi_str_to_stack(t_stack *st, char **av, int ac)
{
	long long	num;
	int			size;
	int			i;

	//printf("atio to stack. ac'%d' .. av[1]:'%s'\n", ac, av[1]);
	st->capacity = ac - 1;
	st->a = (int *)malloc(sizeof(int) * st->capacity);
	st->b = (int *)malloc(sizeof(int) * st->capacity);
	if (!st->a || !st->b)
		quit(st, 1);
	i = ac;
	size = 0;
	while (--i > 0)
	{
		//printf("\tav[%d]: '%s'\t", i, av[i]);
		num = ft_atoi(av[i], st);
		if (num > 2147483647 || num < -2147483648)
			quit(st, 1);
		st->a[size] = (int)num;
		//st->b[size] = (int)num;
		//printf("num:'%lld' > st->a[%d]:'%d'\n", num, size, st->a[size]);
		size++;
	}
	st->size_a = size;
	st->size_b = 0;
	//printf("st->size_a:'%d' capacity:'%d'\n", st->size_a, st->capacity);
}

void	quit(t_stack *st, int err)
{
	//printf("quit:'%d'\n", err);
	if (err == 1 || err == 5)
		write(1, "Error\n", 6);
	if (err != 2 && err != 5)
	{
		free(st->a);
		free(st->b);
	}
	exit (0);
}
