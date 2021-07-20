/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 00:10:30 by oavelar          ###   ########.fr       */
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
	size_t				num_of_philos;
	size_t				philo_eat;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t			init_time;
	size_t			must_eat;
	char			some_died;
	pthread_t		th_death;
	pthread_mutex_t	*fork;
	pthread_mutex_t	die;
	pthread_mutex_t	locked;
	pthread_mutex_t	write;
	t_philo			*philo;
}				t_data;

typedef struct s_philo
{
	size_t			philo_id; // vulgo number
	size_t			last_eat;
	size_t			eat_count;
	char			keep_eat;
	char			ate;
	pthread_t		thread_id;
	t_data			*data;
}		t_philo;

char	init_all(t_data *data, char **av, int ac);
void			clean_free(t_data *data);
unsigned int	get_time(void);
void			sleep_time(long long delay);
void			*routine_philo(void *p);
void			*ft_die(void *philo);

/*int		philo(t_data *global);
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
void	mutex_destroy(t_data *global);*/

#endif
