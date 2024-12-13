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
# include <stdio.h>

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
int         ft_is_revsort(t_stack *stack_b);
int 		ft_pivot(t_stack *stack, int size);
int 		ft_new_pivot(t_stack *stack, int size);
void 		ft_sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot);

void        ft_sort(int size_a, t_stack **stack_a, t_stack **stack_b);
void 		ft_sort2(t_stack **stack_a);
void 		ft_sort3(t_stack **stack_a);
void        ft_sort4(t_stack **stack_a, t_stack **stack_b);
void        ft_sort5(t_stack **stack_a, t_stack **stack_b);
void        ft_rev_sort(int size_b, t_stack **stack_a, t_stack **stack_b);
void 		ft_rev_sort2(t_stack **stack_b);
void 		ft_rev_sort3(t_stack **stack_b);
void        ft_rev_sort4(t_stack **stack_a, t_stack **stack_b);
void        ft_rev_sort5(t_stack **stack_a, t_stack **stack_b);

int         find_min_pos(t_stack *stack);
void        move_min_to_top(t_stack **stack, int min_pos);
int         find_max_pos(t_stack *stack);
void        move_max_to_top(t_stack **stack, int min_pos);
void        sort_three(t_stack **stack_a);
void        sort_five(t_stack **stack_a, t_stack **stack_b);
void        sort_large(t_stack **stack_a, t_stack **stack_b, int size);
void        push_swap(t_stack **stack_a);
void        chunk_sort(t_stack **stack_a, t_stack **stack_b, int size);
void        push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max);
void process_all_chunks(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int chunk_count);
void reinsert_to_a(t_stack **stack_a, t_stack **stack_b);
void generate_sorted_array(t_stack *stack_a, int *sorted_array, int size);
void chunk_sort_optimized(t_stack **stack_a, t_stack **stack_b, int size);
void move_to_top(t_stack **stack, int pos, char stack_name);
void push_closest_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max, int total_elements);
void process_chunks_optimized(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size, int chunk_count);
int calculate_chunk_count(int size);
void process_middle_to_extremes(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size, int chunk_size);



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

void free_stack(t_stack **stack);

//bonus
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char 	*get_line_from_buffer(char **buffer);
char 	*get_next_line(int fd);
void ft_exec(char *instruction, t_stack **stack_a, t_stack **stack_b);
int	ft_strcmp(char *s1, char *s2);
char *get_next_line(int fd);

#endif





