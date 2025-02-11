/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:02 by calberti          #+#    #+#             */
/*   Updated: 2025/02/11 17:06:23 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philosopher_life(void *arg)
{
	t_philo	*philo;
	int stop;

	philo = (t_philo *)arg;
	if (philo->rules->nb_philos == 1)
	{
		print_action(philo, "has taken a fork");
		precise_sleep(philo->rules->time_to_die);
		print_action(philo, "died");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->death_mutex);
        stop = philo->rules->sim_stop;
        pthread_mutex_unlock(&philo->rules->death_mutex);
        if (stop)
            break;
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");

		if (philo->rules->sim_stop)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break;
		}
		print_action(philo, "is eating");
		philo->last_meal = get_time_in_ms();
		philo->meals_eaten++;
		precise_sleep(philo->rules->time_to_eat);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		print_action(philo, "is sleeping");
		precise_sleep(philo->rules->time_to_sleep);

		print_action(philo, "is thinking");
	}
	return (NULL);
}