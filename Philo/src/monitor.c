/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:25:02 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 21:18:28 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	do_monitor(int i, t_rules *rules, long long current_time, long long timesta)
{
	if (current_time - rules->philos[i].last_meal > rules->time_to_die)
	{
		pthread_mutex_lock(&rules->death_mutex);
		rules->sim_stop = 1;
		pthread_mutex_unlock(&rules->death_mutex);
		pthread_mutex_lock(&rules->print_mutex);
		timesta = get_time_in_ms() - rules->start_time;
		printf("%lld %d %s\n", timesta, rules->philos->id, "died");
		pthread_mutex_unlock(&rules->print_mutex);
		pthread_mutex_unlock(&rules->meal_mutex);
		return (1);
	}
	return (0);
}

int	stop_sim(t_rules *rules, int full_philos)
{
	if (rules->must_eat > 0 && full_philos == rules->nb_philos)
	{
		pthread_mutex_lock(&rules->death_mutex);
		rules->sim_stop = 1;
		pthread_mutex_unlock(&rules->death_mutex);
		return (1);
	}
	return (0);
}

int	full_philo(t_rules *rules, int i, int full_philos)
{
	if (rules->must_eat > 0
		&& rules->philos[i].meals_eaten >= rules->must_eat)
		full_philos++;
	pthread_mutex_unlock(&rules->meal_mutex);
	return (full_philos);
}

void	*monitor(void *arg)
{
	t_rules		*rules;
	int			i;
	int			full_philos;
	long long	current_time;
	long long	timestamp;

	rules = (t_rules *)arg;
	timestamp = 0;
	while (1)
	{
		i = -1;
		full_philos = 0;
		while (++i < rules->nb_philos)
		{
			pthread_mutex_lock(&rules->meal_mutex);
			current_time = get_time_in_ms();
			if (do_monitor(i, rules, current_time, timestamp))
				return (NULL);
			full_philos = full_philo(rules, i, full_philos);
		}
		if (stop_sim(rules, full_philos))
			return (NULL);
		usleep(1000);
	}
}
