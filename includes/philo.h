/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/18 12:37:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

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
	int				monitor_flag;
	pthread_t		*thread_id;
	pthread_mutex_t	*mutex_id;
}				t_data;

typedef struct s_philo
{
	int				number;
	int				left_fork;
	int				right_fork;
	long			last_eat;
	int				eat_cnt;
	t_data			*data;
}		t_philo;

int		philo(t_data *global);
void	init_philo(t_data *global, t_philo **philo);
void	init_global(t_data *global);
int		ft_my_atoi(const char *str);
void	sleep_time(long long delay);
long	get_time(void);
void	*routine_philo(void *p);
void	other_fork(t_philo *p, int right_f, int left_f);
void	take_fork(t_philo *p, int left, int right, int p_num);
int		time_die_monitor(t_philo *p, t_data *global);
int		time_eat_monitor(t_philo *p, t_data *global);
void	mutex_destroy(t_data *global);

#endif
