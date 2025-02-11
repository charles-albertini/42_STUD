/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:51:47 by calberti          #+#    #+#             */
/*   Updated: 2025/02/11 16:01:09 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	struct s_rules	*rules;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_rules
{
	int				nb_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	long long		start_time;
	int				sim_stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
	pthread_t		monitor_thread;
	pthread_mutex_t death_mutex;
	pthread_mutex_t meal_mutex;
}	t_rules;

void		init_philosophers(t_rules *rules);
void		*monitor(void *arg);
int			ft_strlen(char *str);
int 		is_digit(int argc, char **argv);
int			ft_atoi(char *str);
int 		ft_parsing(int argc, char **argv, t_rules *rules);
void		*philosopher_life(void *arg);
long long	get_time_in_ms(void);
void		precise_sleep(long long time_in_ms);
void		print_action(t_philo *philo, char *msg);


#endif
