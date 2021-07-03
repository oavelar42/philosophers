/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:59:06 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/03 21:16:10 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_fork(t_philo *p)
{
    if (p->number % 2 == 1)
        usleep(300);
    take_fork(p, p->left_fork, p->right_fork, p->number);
    printf("%lld_in_ms %d has taken a fork\n", get_time() - p->data->base_time, p->number);
	//printf("has taken a "YEL"fork"YEL".\n");
    /*
    pthread_mutex_lock(p->mutex_left);
    pthread_mutex_lock(p->mutex_right);
    pthread_mutex_lock(p->mutex_monitor);
    printf("%lld_in_ms %d has taken a fork\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);*/
}

void    philo_eat(t_philo *p)
{
    if (p->data->fork[p->left_fork] == p->number
        && p->data->fork[p->right_fork] == p->number)
    {
        p->last_eat = get_time();
        printf(YEL"%lld_in_ms %d is eating\n", get_time() - p->data->base_time, p->number);
		//printf("is "YEL"eating"GRE"!\n");

    }
    /*pthread_mutex_lock(p->mutex_monitor);
    p->last_eat_time = get_time();
    printf("%lld_in_ms %d is eating\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);
    sleep_time(p->time_to_eat);
    pthread_mutex_unlock(p->mutex_left);
    pthread_mutex_unlock(p->mutex_right);*/
}

void		philo_sleep(t_philo *p)
{

    printf(GRE"%lld_in_ms %d is sleeping\n", get_time()
        - p->data->base_time, p->number);
	//printf("is "YEL"sleeping"GRE"!\n");
    other_fork(p, p->right_fork, p->left_fork);
    sleep_time(p->data->time_to_sleep);
	/*pthread_mutex_lock(p->mutex_monitor);
	printf("%lld_in_ms %d is sleeping\n", get_time() - p->time, p->id);
	pthread_mutex_unlock(p->mutex_monitor);
	sleep_time(p->time_to_sleep);*/
}

void    philo_think(t_philo *p)
{
    printf(BLU"%lld_in_ms %d is thinking\n", get_time()
        - p->data->base_time, p->number);
	//printf("is "YEL"thinking"GRE"!\n");
    /*pthread_mutex_lock(p->mutex_monitor);
    printf("%lld_in_ms %d is thinking\n", get_time() - p->time, p->id);
    pthread_mutex_unlock(p->mutex_monitor);*/
}

void    *routine_philo(void *p)
{
    t_philo     *philo;
    t_data    *global;

    philo = (t_philo *)p;
    global = philo->data;
    while (1)
    {
        philo_fork(philo);
        usleep(200);
        if (global->monitor_flag == 1)
            break ;
        philo_eat(philo);
        usleep(200);
        if (global->monitor_flag == 1)
            break ;
        philo_sleep(philo);
        usleep(200);
        if (global->monitor_flag == 1)
            break ;
        philo_think(philo);
    }
    return (p);
}