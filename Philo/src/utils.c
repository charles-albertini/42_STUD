/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:33 by calberti          #+#    #+#             */
/*   Updated: 2025/02/27 15:55:17 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_sleep(long long time_in_ms)
{
	long long	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < time_in_ms)
		usleep(100);
}

void	print_action(t_philo *philo, char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->rules->print_mutex);
	if (!philo->rules->sim_stop)
	{
		timestamp = get_time_in_ms() - philo->rules->start_time;
		printf("%lld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
