/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:41 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/30 21:17:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_philo(void *phi)
{
    t_philo     *p;
    pthread_t    main;
    int          count;

    count = 0;
    p = (t_philo *)phi;
    if (p->id % 2 != 0)
        sleep_time(p->time_to_eat);
    pthread_create(&main, NULL, &monitor, (void *)p);
    pthread_detach(main);
    while (p->live && (!p->end_eat || count < p->end_eat_amount))
    {
        philo_fork(p);
        philo_sleep(p);
        count++;
    }
    p->live = false;
    if (p->end_eat && count == p->end_eat_amount)
        p->data->meals++;
    return (NULL);
}

void    delete_philo(int end, pthread_t **ph2)
{
    int count;

    count = 0;
    while (count < end)
        pthread_detach((*ph2)[count++]);
}

void    ft_check_meals(t_philo *in, pthread_t **ph2)
{
    int idx;
    int end;

    idx = 0;
    end = in[idx].number_of_philo;
    while (!in->data->stop && (in->data->meals) < end)
        sleep_time(1);
    if (in->data->stop || in->data->meals == end)
        delete_philo(end, ph2);
    if (!in->data->stop && in->data->meals == end)
    {
        pthread_mutex_lock(in->mutex_monitor);
        printf("philo all ate!\n");
    }
}

int init_process(t_philo *in, pthread_t **ph2)
{
    int index;

    index = 0;
    while (index < in->number_of_philo)
    {
        pthread_create(&((*ph2)[index]), NULL, ft_philo, (void *)&(in[index]));
        index++;
    }
    if (in->end_eat)
        ft_check_meals(in, ph2);
    /*else
        ft_check_die(in, ph2);*/
    return (1);
}

