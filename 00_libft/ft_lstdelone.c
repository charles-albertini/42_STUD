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

t_list *ft_lstlast(t_list *lst)
{
	int i;
	int len;
	
	i = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		lst = lst -> next;
		i ++;
	}
	return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst == NULL)
		return ;
	back = ft_lstlast(*lst);
	back->next = new;
}
void del(void *lst) // PAS DEMANDE del un lst
{
	t_list *supp = (t_list *)lst;
    if (lst == NULL)
        return;
    supp->content = NULL;
}

t_list *ft_getlst(t_list *lst, int index) // PAS DEMANDE donne lst index 
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
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst); // quand on fait free(lst) on libere la memoire du noeud en lui meme, pas la memoire de content (ca c'est *del qui le fait) ni la memoire de next.
			  //sauf que le noeud n'existe plus donc on ne peut plus y acceder meme si theoriquement next est pas supp
}
void aff_lst(t_list *lst) // PAS DEMANDE affiche list
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

	t_list *first = ft_lstnew(&nb);
	t_list *new = ft_lstnew(&nb2);
	t_list *new2 = ft_lstnew(&nb3);

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

