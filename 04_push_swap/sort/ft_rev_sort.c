#include "../push_swap.h"

void    ft_rev_sort(int size_b, t_stack **stack_a, t_stack **stack_b)
{
    if (size_b == 2 && ft_is_revsort(*stack_b) == 1)
        ft_rev_sort2(stack_b);
    if (size_b == 3 && ft_is_revsort(*stack_b) == 1)
        ft_rev_sort3(stack_b);
    if (size_b == 4 && ft_is_revsort(*stack_b) == 1)
        ft_rev_sort4(stack_a, stack_b);
    if (size_b == 5 && ft_is_revsort(*stack_b) == 1)
        ft_rev_sort5(stack_a, stack_b);
}