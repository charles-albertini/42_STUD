/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:27 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 18:14:05 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < argc -1)
	{
		if (ft_strlen(argv[i]) == 0)
			return (2);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			while (argv[i][j] > 47 && argv[i][j] < 58)
				j++;
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			if (argv[i][j] != '\0')
				return (1);
		}
		if (ft_atoi(argv[i]) == -1)
			return (3);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		num = num * 10 + (str[i] - '0');
		if (num > 2147483647)
			return (-1);
		i++;
	}
	return ((int)num);
}

int	ft_parsing(int argc, char **argv, t_rules *rules)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: 5 or 6 args\n"), 1);
	if (is_digit(argc, argv) == 1 || is_digit(argc, argv) == 3)
		return (printf("Error: wrong arg\n"), 1);
	if (is_digit(argc, argv) == 2)
		return (printf("Error: empty arg\n"), 1);
	rules->nb_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->must_eat = -1;
	if (argc == 6)
		rules->must_eat = ft_atoi(argv[5]);
	if (rules->nb_philos == 0 || rules->nb_philos > 200
		|| rules->time_to_die == 0 || rules->time_to_eat == 0
		|| rules->time_to_sleep == 0 || (argc == 6 && rules->must_eat == 0))
	{
		printf("Error: can't work\n");
		return (1);
	}
	return (0);
}
