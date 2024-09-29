#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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
int			ft_strlen(char *str);
int			ft_atoi(char *str);
t_stack		*ft_getarg(int argc, char **argv);
t_stack		*ft_getarg_str(char *argv);
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

//bonus
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char 	*get_line_from_buffer(char **buffer);
char 	*get_next_line(int fd);
void ft_exec(char *instruction, t_stack **stack_a, t_stack **stack_b);
int	ft_strcmp(char *s1, char *s2);
char *get_next_line(int fd);

#endif





