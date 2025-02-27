/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:44:48 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 18:46:49 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_mutex(t_rules rules)
{
	pthread_mutex_destroy(&rules.print_mutex);
	pthread_mutex_destroy(&rules.death_mutex);
	pthread_mutex_destroy(&rules.meal_mutex);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		i;

	if (ft_parsing(argc, argv, &rules) != 0)
		return (1);
	init_philosophers(&rules);
	if (rules.nb_philos != 1)
		pthread_create(&rules.monitor_thread, NULL, monitor, &rules);
	i = 0;
	while (i < rules.nb_philos)
	{
		pthread_create(&rules.philos[i].thread, NULL,
			philosopher_life, &rules.philos[i]);
		i++;
	}
	i = 0;
	while (i < rules.nb_philos)
	{
		pthread_join(rules.philos[i].thread, NULL);
		i++;
	}
	if (rules.nb_philos != 1)
		pthread_join(rules.monitor_thread, NULL);
	return (destroy_mutex(rules), free(rules.forks), free(rules.philos), 0);
}
