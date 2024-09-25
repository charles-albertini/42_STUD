#include "push_swap.h"

void ft_lstdellast(t_stack **lst)
{
    t_stack *temp;
    t_stack *prev;

    // Si la liste est vide, ne rien faire
    if (*lst == NULL)
        return;

    // Si la liste n'a qu'un seul élément, le supprimer et mettre lst à NULL
    if ((*lst)->next == NULL) {
        free(*lst);
        *lst = NULL;
        return;
    }

    // Parcourir la liste jusqu'à l'avant-dernier élément
    temp = *lst;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Supprimer le dernier élément et mettre à jour le pointeur de l'avant-dernier à NULL
    prev->next = NULL;
    free(temp);
}
