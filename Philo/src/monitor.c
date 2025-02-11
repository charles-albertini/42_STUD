/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:25:02 by calberti          #+#    #+#             */
/*   Updated: 2025/02/11 17:10:21 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *monitor(void *arg)
{
    t_rules *rules;
    int i;
    int full_philos;
    long long current_time;
	long long	timestamp;

    rules = (t_rules *)arg;
    while (1)
    {
        i = -1;
        full_philos = 0;
        while (++i < rules->nb_philos)
        {
            pthread_mutex_lock(&rules->meal_mutex);
            current_time = get_time_in_ms();
            if (current_time - rules->philos[i].last_meal > rules->time_to_die)
            {
                pthread_mutex_lock(&rules->death_mutex);
                rules->sim_stop = 1;
                pthread_mutex_unlock(&rules->death_mutex);
				
				//print "died"
				pthread_mutex_lock(&rules->print_mutex);
				timestamp = get_time_in_ms() - rules->start_time; 
				printf("%lld %d %s\n", timestamp, rules->philos->id, "died");
				pthread_mutex_unlock(&rules->print_mutex);
				
                pthread_mutex_unlock(&rules->meal_mutex);
                return (NULL);
            }
            if (rules->must_eat > 0 && rules->philos[i].meals_eaten >= rules->must_eat)
                full_philos++;
            pthread_mutex_unlock(&rules->meal_mutex);
        }
        if (rules->must_eat > 0 && full_philos == rules->nb_philos)
        {
            pthread_mutex_lock(&rules->death_mutex);
            rules->sim_stop = 1;
            pthread_mutex_unlock(&rules->death_mutex);
            return (NULL);
        }
        usleep(1000);
    }
}