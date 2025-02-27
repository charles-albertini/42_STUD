/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:19:20 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 16:23:54 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philosophers(t_rules *rules)
{
	int	i;

	rules->sim_stop = 0;
	pthread_mutex_init(&rules->death_mutex, NULL);
	pthread_mutex_init(&rules->meal_mutex, NULL);
	rules->start_time = get_time_in_ms();
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
	rules->philos = malloc(sizeof(t_philo) * rules->nb_philos);
	i = -1;
	while (i++ < rules->nb_philos - 1)
		pthread_mutex_init(&rules->forks[i], NULL);
	pthread_mutex_init(&rules->print_mutex, NULL);
	i = 0;
	while (i < rules->nb_philos)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].last_meal = get_time_in_ms();
		rules->philos[i].rules = rules;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 1) % rules->nb_philos];
		i++;
	}
}
