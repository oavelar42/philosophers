/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:41 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/03 19:40:16 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_fork(t_philo *p, int left, int right, int p_num)
{
    pthread_mutex_lock(&p->data->mutex_id[left]);
    pthread_mutex_lock(&p->data->mutex_id[right]);
    p->data->fork[left] = p_num;
    p->data->fork[right] = p_num;
}

void	other_fork(t_philo *p, int right_f, int left_f)
{
	p->data->fork[right_f] = -1;
	p->data->fork[left_f] = -1;
	pthread_mutex_unlock(&p->data->mutex_id[right_f]);
	pthread_mutex_unlock(&p->data->mutex_id[left_f]);
}

// SEGMENTTAKOPGJOPSGPOSGRK MERDA

/*void    *ft_philo(void *phi)
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
        philo_eat(p);
        philo_sleep(p);
        philo_think(p);
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

void    ft_check_die(t_philo *in, pthread_t **ph2)
{
    int end;

    end = in[0].number_of_philo;
    while (!in->data->stop)
        sleep_time(1);
    if (in->data->stop)
        delete_philo(end, ph2);
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
    else
        ft_check_die(in, ph2);
    return (1);
}
*/
