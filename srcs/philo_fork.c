/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:41 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 11:53:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	take_fork(t_philo *p, int left, int right, int p_num)
{
	pthread_mutex_lock(&p->data->mutex_id[left]);
	pthread_mutex_lock(&p->data->mutex_id[right]);
	p->data->fork[left] = p_num;
	p->data->fork[right] = p_num;
	if (p->data->fork)
		printf(MAG"[%ld] Philosopher's %d has taken a fork\n", get_time()
			- p->data->init_time, p->philo_id + 1);
}

static void	other_fork(t_philo *p)
{
	pthread_mutex_unlock(&(p->data->fork[p->philo_id]));
	pthread_mutex_unlock(&p->data->fork[(p->philo_id + 1) % p->data->num_of_philos]);
	p->ate = 0;
	printf(MAG"[%ld] Philosopher's is sleeping\n", get_time()
			- p->data->num_of_philos);
	usleep(200);
}
*/