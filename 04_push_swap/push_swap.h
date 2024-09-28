#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
    int 	*content;
    struct s_stack *next;
} t_stack;

t_stack		*ft_lstnew(void *content);
void 		aff_lst(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void 		ft_lstdelone(t_stack **lst);
void 		ft_lstdellast(t_stack **lst);
t_stack 	*ft_lstnull(int size);
//void		ft_lstclear(t_stack **lst, void (*del)(t_stack *));
//void		ft_lstiter(t_stack *lst, void (*f)(void *));
//t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(t_stack *));
//void 		ft_del(t_stack *lst);
//t_stack 	*ft_getlst(t_stack *lst, int index);
//void 		ft_addone (t_stack *nb);
//void 		*double_value(t_stack *content);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
t_stack		*ft_getarg(int argc, char **argv);
int 		ft_findarg(int *nb, t_stack *first);
int 		ft_only_int (char *str);
int 		ft_issort(t_stack *stack_a);
int 		ft_pivot(t_stack *stack, int size);
int 		ft_new_pivot(t_stack *stack, int size);
void 		ft_sort3(t_stack **stack_a);
void 		ft_rev_sort3(t_stack **stack_b);
void 		ft_sort2(t_stack **stack_a);
void 		ft_rev_sort2(t_stack **stack_b);
void 		ft_sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot);

void 		ft_sa(t_stack **stack_a);
void 		ft_sb(t_stack **stack_b);
void 		ft_ss(t_stack **stack_a, t_stack **stack_b);
void 		ft_pa(t_stack **stack_a, t_stack **stack_b);
void 		ft_pb(t_stack **stack_a, t_stack **stack_b);
void 		ft_ra(t_stack **stack_a);
void 		ft_rb(t_stack **stack_b);
void 		ft_rr(t_stack **stack_a, t_stack **stack_b);
void 		ft_rra(t_stack **stack_a);
void 		ft_rrb(t_stack **stack_b);
void 		ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
