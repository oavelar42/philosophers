/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:59:06 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/07 20:57:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_fork(t_philo *p)
{
    if (p->number % 2 == 1)
        usleep(300);
    take_fork(p, p->left_fork, p->right_fork, p->number);
    if (p->data && get_time())
        printf(MAG"[%lld] Philosopher's %d has taken a fork\n", get_time() - p->data->base_time, p->number);
    /*
    pthread_mutex_lock(p->left_fork);
    pthread_mutex_lock(p->right_fork);
    pthread_mutex_lock(p->number);
    printf(MAG"[%lld] Philosopher's %d has taken a fork\n", get_time() - p->data->base_time, p->number);
    pthread_mutex_unlock(p->old_state);*/
}

void    philo_eat(t_philo *p)
{
    if (p->data->fork[p->left_fork] == p->number
        && p->data->fork[p->right_fork] == p->number)
    {
       /* p->last_eat = get_time();
        printf(YEL"[%lld] Philosopher's %d is eating\n", get_time() - p->data->base_time, p->number);
    }*/
    //pthread_mutex_lock(p->state);
    //p->last_eat = get_time();
    printf(YEL"[%lld] Philosopher's %d is eating\n", get_time() - p->data->base_time, p->number);
    sleep_time(p->data->time_to_eat);
    //pthread_mutex_unlock(p->data->mutex_id);
    
    //pthread_mutex_unlock(p->left_fork);
   //pthread_mutex_unlock(p->right_fork);
    }
}

void		philo_sleep(t_philo *p)
{
    p->last_eat = get_time();
    printf(GRE"[%lld] Philosopher's %d is sleeping\n", get_time()
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
    printf(BLU"[%lld] Philosopher's %d is thinking\n", get_time()
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