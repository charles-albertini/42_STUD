#include "push_swap.h"

void ft_lstdelone(t_stack **lst) {
    t_stack *temp;

    if (*lst == NULL)
        return;  // La liste est vide, rien à supprimer

    // Pointer vers le premier élément à supprimer
    temp = *lst;

    // Mettre à jour la tête de la liste pour qu'elle pointe vers le deuxième élément
    *lst = (*lst)->next;

    // Libérer la mémoire de l'ancien premier élément
    free(temp);
}

/*
#include <stdio.h>

void del(void *lst) // PAS DEMANDE del un lst
{
    t_stack *supp = (t_stack *)lst;
    if (lst == NULL)
        return;
    supp->content = NULL;
}

 t_stack *ft_getlst(t_stack *lst, int index) // PAS DEMANDE donne lst index
{
    int i = 0;

    while (lst != NULL)
    {
        if (i == index)
            return lst;
        lst = lst->next;
        i++;
    }
    return NULL;  // Si l'indice est hors de la portée de la liste
}

void aff_lst(t_stack *lst) // PAS DEMANDE affiche list
{
	while (lst != NULL)
	{
		if (lst -> content != NULL)
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
	int nb3 = 11;
	int size;

	t_stack *first = ft_lstnew(&nb);
	t_stack *new = ft_lstnew(&nb2);
	t_stack *new2 = ft_lstnew(&nb3);

	ft_lstadd_front(&first, new);
	ft_lstadd_back(&first, new2);

	printf("liste :\n");
	aff_lst(first);

	size = ft_lstsize(first);
	printf("size : %d\n", size);

	printf("last list :");
	aff_lst(ft_lstlast(first));

	ft_lstdelone(ft_getlst(first, 1), del);
	aff_lst(first);



	return (0);
}
*/
