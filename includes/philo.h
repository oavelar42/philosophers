/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/27 19:10:47 by oavelar          ###   ########.fr       */
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

/*bool					g_stop;
int						g_meals;*/

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
}           t_philo;

long long       ft_my_atoi(const char *s);
long long       get_time(void);

int             parse_init(t_philo **input, int ac, char **av);

int 			init_thread(t_philo *in, pthread_t **ph2, pthread_mutex_t **mutx2);
int 			init_mutex(t_philo *in, pthread_mutex_t **mutx2);
#endif