#ifndef P_SWAP_H
# define P_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stab
{
    int    *a;
    int    *b;
    int    top_a;
    int    top_b;
}	t_stack;

void        sb(int *t, int top, char c);
void        sa(int *t, int top, char c);
void        ss(int *t_a, int top_a, int *t_b, int top_b);
void        pb(int *t_a, int *top_a, int *t_b, int *top_b);
void        pa(int *t_a, int *top_a, int *t_b, int *top_b);
void        ra(int *t, int top, char c);
void        rb(int *t, int top, char c);
void        rr(int *t_a, int top_a, int *t_b, int top_b);
void        rra(int *t, int top, char c);
void        rrb(int *t, int top, char c);
void        rrr(int *t_a, int top_a, int *t_b, int top_b);
int			find_j(int *t, int top, int j);
int			check_arg(char **v);
int			check_repeat(int *t, int top);
long long	ft_atoi(char *str, t_stack *var, char **v);
void        indexing(t_stack *var);
void        push_sorted_to_b(t_stack *var);
void        push_sorted_to_a(t_stack *var);
int			check_if_sorted(int *t, int top);
void        sort_3nb(t_stack *var, int c);
int			find_small(int *t, int top);
int			find_i(int *t, int top, int find);
void        push_to_b(t_stack *var);
void        sort_5nb(t_stack *var, int c);
void        ft_putstr(char *s);
char        *ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char        **ft_split(char *s, char c);
void        qu(int c);
void        quit(t_stack *va, int c, char **v);
int			check_space(char **v);

#endif