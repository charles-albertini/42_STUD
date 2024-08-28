#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
}		t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);

}
void ft_lstadd_front(t_list **lst, t_list *new) 
{
	if ((lst == NULL) || (new == NULL))
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	int nb = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		nb ++;
	}
	return (nb);
}
void aff_lst(t_list *lst)
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
	int nb = 10;
	int nb2 = 9;
	int nb3 = 8;
	int size;
	t_list *first = ft_lstnew(&nb);
	t_list *new = ft_lstnew(&nb2);
	t_list *new2 = ft_lstnew(&nb3);
	ft_lstadd_front(&first, new);
	ft_lstadd_front(&first, new2);
	size = ft_lstsize(first);
	aff_lst(first);
	printf("\n%d\n", size);
	

	
	return (0);
}

