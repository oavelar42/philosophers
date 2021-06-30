/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/30 21:37:11 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data
{
	bool		stop;
	int			meals;
}				t_data;

typedef struct s_philo
{
	int					id;
	int					status;
	pthread_mutex_t		*mutex_left;
	pthread_mutex_t		*mutex_right;
	pthread_mutex_t		*mutex_monitor;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	bool				end_eat;
	int					end_eat_amount;
	int					eat_amount;
	int					meals;
	bool				live;
	long long			last_eat_time;
	long long			time;
	struct s_data		*data;
}           t_philo;

long long	ft_my_atoi(const char *s);
long long	get_time(void);
void		sleep_time(long long delay);

int			parse_init(t_philo **input, int ac, char **av);

int			init_thread(t_philo *in, pthread_t **ph2, pthread_mutex_t **mutx2);
int			init_mutex(t_philo *in, pthread_mutex_t **mutx2);
void		clear_program(t_philo **in, pthread_mutex_t **mu2,
			pthread_t **ph2);

int			init_process(t_philo *in, pthread_t **ph2);
void		*ft_philo(void *p);
void		ft_check_meals(t_philo *in, pthread_t **ph2);
void		delete_philo(int end, pthread_t **ph2);

void		philo_fork(t_philo *p);
void		philo_eat(t_philo *p);
void		philo_sleep(t_philo *p);
void		philo_think(t_philo *p);
void		*monitor(void *p);
#endif