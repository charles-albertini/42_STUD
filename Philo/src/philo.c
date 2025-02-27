/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:02 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 18:55:37 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	one_philo(t_philo *philo)
{
	if (philo->rules->nb_philos == 1)
	{
		print_action(philo, "has taken a fork");
		precise_sleep(philo->rules->time_to_die);
		print_action(philo, "died");
		return (1);
	}
	return (0);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}

void	eat_sleep_think(t_philo *philo)
{
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

void	*philosopher_life(void *arg)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)arg;
	if (one_philo(philo))
		return (NULL);
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->death_mutex);
		stop = philo->rules->sim_stop;
		pthread_mutex_unlock(&philo->rules->death_mutex);
		if (stop)
			break ;
		take_fork(philo);
		if (philo->rules->sim_stop)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		eat_sleep_think(philo);
	}
	return (NULL);
}
