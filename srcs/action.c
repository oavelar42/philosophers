/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:59:06 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/01 15:57:47 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void    philo_fork(t_philo *p)
{
    pthread_mutex_lock(p->mutex_left);
    pthread_mutex_lock(p->mutex_right);
    pthread_mutex_lock(p->mutex_monitor);
    printf("%lld_in_ms %d has taken a fork\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);
}

void    philo_eat(t_philo *p)
{
    pthread_mutex_lock(p->mutex_monitor);
    p->last_eat_time = get_time();
    printf("%lld_in_ms %d is eating\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);
    sleep_time(p->time_to_eat);
    pthread_mutex_unlock(p->mutex_left);
    pthread_mutex_unlock(p->mutex_right);
}

void		philo_sleep(t_philo *p)
{
	pthread_mutex_lock(p->mutex_monitor);
	printf("%lld_in_ms %d is sleeping\n", get_time() - p->time, p->id);
	pthread_mutex_unlock(p->mutex_monitor);
	sleep_time(p->time_to_sleep);
}

void    philo_think(t_philo *p)
{
    pthread_mutex_lock(p->mutex_monitor);
    printf("%lld_in_ms %d is thinking\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);
}

void    *monitor(void *p)
{
    t_philo *phi;

    phi = (t_philo *)p;
    while (phi->live)
    {
        if (get_time() - phi->last_eat_time > phi->time_to_die)
        {
            pthread_mutex_lock(phi->mutex_monitor);
            printf("%lld_in_ms %d died\n", get_time() - phi->time, phi->id);
            phi->data->stop = true;
            phi->live = false;
        }
    }
    return (NULL);
}*/