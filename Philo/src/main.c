/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:44:48 by calberti          #+#    #+#             */
/*   Updated: 2025/02/11 17:04:00 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		i;

	if (ft_parsing(argc, argv, &rules) != 0)
		return (1);
	init_philosophers(&rules);
	i = 0;
	while (i < rules.nb_philos)
	{
		pthread_create(&rules.philos[i].thread, NULL,
			philosopher_life, &rules.philos[i]);
		i++;
	}
	pthread_create(&rules.monitor_thread, NULL, monitor, &rules);
	i = 0;
	while (i < rules.nb_philos)
	{
		pthread_join(rules.philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&rules.print_mutex);
	pthread_mutex_destroy(&rules.death_mutex);
	pthread_mutex_destroy(&rules.meal_mutex);
	free(rules.forks);
	free(rules.philos);
	return (0);
}