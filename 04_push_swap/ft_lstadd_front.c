#include "push_swap.h"

/* on veut ajouter un element au debut de la list on dit donc que
 new -> next point vers le premier truc pour qu'il se mette avant
 et ensuite on dit que mnt le premiere element est new on a donc
 new en premier element qui point maintenent vers *lst qui est devenue
 le deuxieme element */

void	ft_lstadd_front(t_stack **lst, t_stack *new) //**lst on modifie le poiteur de lst, §pas lst
{
	if ((lst == NULL) || (new == NULL))
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}



