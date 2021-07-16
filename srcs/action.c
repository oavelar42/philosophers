/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:59:06 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/16 14:49:30 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_fork(t_philo *p)
{
    if (p->number % 2 == 1)
        usleep(300);
    take_fork(p, p->left_fork, p->right_fork , p->number);
    if (p->data && get_time())
    printf(MAG"[%lld] Philosopher's %d has taken a fork\n", get_time() - p->data->base_time, p->number + 1);
}

void    philo_eat(t_philo *p)
{
    if (p->data->fork[p->left_fork] == p->number
        && p->data->fork[p->right_fork] == p->number)
    {
    p->last_eat = get_time();
    printf(YEL"[%lld] Philosopher's %d is eating\n", get_time() - p->data->base_time, p->number + 1);
    p->eat_cnt++;
    }
    sleep_time(p->data->time_to_eat);
}

void		philo_sleep(t_philo *p)
{
    p->last_eat = get_time();
    printf(GRE"[%lld] Philosopher's %d is sleeping\n", get_time()
        - p->data->base_time, p->number + 1);
    other_fork(p, p->right_fork, p->left_fork);
    sleep_time(p->data->time_to_sleep);
}

void    philo_think(t_philo *p)
{
    printf(BLU"[%lld] Philosopher's %d is thinking\n", get_time()
       - p->data->base_time, p->number + 1);
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