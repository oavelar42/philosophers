/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:58:13 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/16 14:50:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_global(t_data *global)
{
	int	count;

	global->base_time = get_time();
	global->cur_time = 0;
	global->monitor_flag = 0;
	global->mutex_id = malloc(sizeof(pthread_mutex_t) * global->num_of_philos);
	count = -1;
	while (++count < global->num_of_philos)
		pthread_mutex_init(&(global->mutex_id)[count], NULL);
	pthread_mutex_init(&global->mutex_print, NULL);
	global->fork = malloc(sizeof(pthread_t) * global->num_of_philos);
	memset(global->fork, -1, global->num_of_philos);
	global->thread_id = malloc(sizeof(pthread_t) * global->num_of_philos);
}

void	init_philo(t_data *global, t_philo **philo)
{
	int count;

	count = -1;
	*philo = malloc(sizeof(t_philo) * global->num_of_philos);
	while (++count < global->num_of_philos)
	{
		(*philo)[count].number = count;
		(*philo)[count].old_state = 0;
		(*philo)[count].last_eat = get_time();
		(*philo)[count].eat_cnt = 0;
		if (count == 0)
			(*philo)[count].left_fork = global->num_of_philos - 1;
		else
			(*philo)[count].left_fork = count - 1;
		(*philo)[count].right_fork = count;
		(*philo)[count].data = global;
	}
}

void	mutex_destroy(t_data *global)
{
	int	count;

	count = -1;
	while (++count < global->num_of_philos)
	{
		usleep(10);
		pthread_mutex_destroy(&(global->mutex_id)[count]);
	}
	usleep(10);
	pthread_mutex_destroy(&global->mutex_print);
}