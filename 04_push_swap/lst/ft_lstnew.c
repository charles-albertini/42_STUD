#include "../push_swap.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
/*
#include <stdio.h>

void aff_lst(t_stack *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", *(int *)(lst -> content));
		lst = lst -> next;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int nb = 8;
	//int *val = nb;
	t_stack *first = ft_lstnew(&nb);
	aff_lst(first);



	return (0);
}
*/
