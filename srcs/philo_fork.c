/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:41 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/17 23:36:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *p, int left, int right, int p_num)
{
	if (p_num % 2)
		pthread_mutex_lock(&p->data->mutex_id[left]);
	else
		pthread_mutex_lock(&p->data->mutex_id[right]);
	p->data->fork[left] = p_num;
	p->data->fork[right] = p_num;
   	//if (p->data )//&& p->number % 2)
	//	printf(MAG"[%lld] Philosopher's %d has taken a fork\n", get_time() - p->data->base_time, p->number + 1);
}

void	other_fork(t_philo *p, int right_f, int left_f)
{
	p->data->fork[right_f] = -1;
	p->data->fork[left_f] = -1;
	pthread_mutex_unlock(&p->data->mutex_id[right_f]);
	pthread_mutex_unlock(&p->data->mutex_id[left_f]);
	//if (p->data && p->number % 2)
	//rintf(MAG"[%lld] Philosopher's %d has taken a fork\n", get_time() - p->data->base_time, p->number + 1);
}
