/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:41 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 13:56:47 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	philo_fork(t_philo *p)
{
	size_t	forks;

	forks = (p->philo_id + 1) % p->data->num_of_philos;
	pthread_mutex_lock(&(p->data->fork[p->philo_id]));
	printf(MAG"[%ld] Philosopher's %lu has taken a fork\n", get_time() - p->data->init_time, p->philo_id + 1);
	if (p->data->num_of_philos == 1)
	{
		sleep(200);
		pthread_mutex_unlock(&(p->data->fork[p->philo_id]));
		pthread_exit(0);
	}
	pthread_mutex_lock(&(p->data->fork[forks]));
	printf(MAG"[%ld] Philosopher's %lu has taken a fork\n", get_time() - p->data->init_time, p->philo_id + 1);
}

static void	other_fork(t_philo *p)
{
	pthread_mutex_unlock(&(p->data->fork[p->philo_id]));
	pthread_mutex_unlock(&p->data->fork[(p->philo_id + 1) % p->data->num_of_philos]);
	p->ate = 0;
	printf(MAG"[%ld] Philosopher's is sleeping\n", get_time()
			- p->data->num_of_philos);
	usleep(200);
}*/