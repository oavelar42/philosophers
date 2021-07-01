/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/01 16:17:50 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				time_must_eat_flag;
	int				*fork;
	long			base_time;
	long			cur_time;
	int				monitor_flag;
	pthread_t		*thread_id;
	pthread_t		tid_print;
	pthread_mutex_t	*mutex_id;
	pthread_mutex_t	mutex_print;
}				t_data;

typedef struct s_philo
{
	int				number;
	int				left_fork;
	int				right_fork;
	int				old_state;
	int				state;
	long			last_eat;
	int				eat_cnt;
	t_data			*data;
}           t_philo;

int			philo(t_data *global);
long long	ft_my_atoi(const char *s);
long long	get_time(void);
void		sleep_time(long long delay);
void   		*routine_philo(void *p);

#endif