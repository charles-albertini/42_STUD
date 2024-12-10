#include "../push_swap.h"


t_stack	*ft_getarg(int argc, char **argv)
{
	int *nb_add;
	t_stack *first;
	t_stack *new;

	argc--;
	if (ft_only_int (argv[argc]))
		return (NULL);
	nb_add = malloc(sizeof(int));
	if ((ft_atoi(argv[argc]) == 1) && (ft_strlen(argv[argc]) > 9))
			return (NULL);
		else
			*nb_add = ft_atoi(argv[argc]);
	first = ft_lstnew(nb_add);
	while (argc > 1)
	{
		argc--;
		if (ft_only_int (argv[argc])) // on ne prend que si c'est un int
			return (NULL);
		nb_add = malloc(sizeof(int));
		if ((ft_atoi(argv[argc]) == 1) && (ft_strlen(argv[argc]) > 9))
			return (NULL);
		else
			*nb_add = ft_atoi(argv[argc]);
		if (ft_findarg(nb_add, first) == 0) // on verifie que y a pas de doublon
			return (NULL);
		new = ft_lstnew(nb_add);
		ft_lstadd_front(&first, new);
	}
	return (first);
}
