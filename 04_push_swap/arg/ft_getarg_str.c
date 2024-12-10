#include "../push_swap.h"
#include <stdio.h>

t_stack	*ft_getarg_str(char *argv)
{
	int *nb_add;
	t_stack *first;
	t_stack *new;
	char *temp;
	int i;
	int j;


	i = 0;
	j = 0;
	temp = malloc(ft_strlen(argv));
	nb_add = malloc(sizeof(int));

	if (ft_only_int (argv))
		return (NULL);
	while (argv[i] == 32)
		i++;
	if (argv[i] == 43 || argv[i] == 45)
		i++;
	while (argv[i] >= 48 && argv[i] <= 57)
	{
		temp[j] = argv[i];
		i++;
		j++;
	}

	if ((ft_atoi(temp) == 1) && (ft_strlen(temp) > 9))
			return (NULL);
		else
			*nb_add = ft_atoi(temp);
	first = ft_lstnew(nb_add);
	free(temp);
	temp = malloc(ft_strlen(argv));

	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i] == 32)
			i++;
		if (argv[i] == 43 || argv[i] == 45)
			i++;
		while (argv[i] >= 48 && argv[i] <= 57)
		{
			temp[j] = argv[i];
			i++;
			j++;
		}
		nb_add = malloc(sizeof(int));
		if ((ft_atoi(temp) == 1) && (ft_strlen(temp) > 9))
			return (NULL);
		else
			*nb_add = ft_atoi(temp);
		new = ft_lstnew(nb_add);
		ft_lstadd_back(&first, new);
		/*
		if (ft_findarg(nb_add, first) == 0)
		{
			printf("la\n");
			return (NULL);
		}
		*/

		free(temp);
		temp = malloc(ft_strlen(argv));
	}
	return (first);
}


