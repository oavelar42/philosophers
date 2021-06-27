/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:31 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/27 19:14:56 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_thread(t_philo *in, pthread_t **ph2, pthread_mutex_t **mutx2)
{
    int         index;
    pthread_t   *ph;

    ph = *ph2;
    ph = (pthread_t *)malloc(sizeof(pthread_t) * in[0].number_of_philo);
    if (!ph)
        return (printf("Error : Thread malloc error!\n"));
    index = 0;
    while (index < in[index].number_of_philo)
    {
        in[index].id = index;
        in[index].mutex_left = &(*mutx2)[index];
        if (index + 1 == in[index].number_of_philo)
            in[index].mutex_right = &(*mutx2)[0];
        else
            in[index].mutex_right = &(*mutx2)[index + 1];
        index++;
    }
    *ph2 = ph;
    return (1);
}

int init_mutex(t_philo *in, pthread_mutex_t **mutx2)
{
    int             index;
    pthread_mutex_t *pth;

    mutx2 = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
        * in[0].number_of_philo);
    if (!mutx2)
        return (printf("Error : Mutex error!\n"));
    pth = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (!pth)
        return (printf("Error : Pth error"));
    index = 0;
    pthread_mutex_init(pth, NULL);
    while (index < in[0].number_of_philo)
    {
        pthread_mutex_init(&(*mutx2)[index], NULL);
        in[index].mutex_monitor = pth;
        index++;
    }
    return (1);
}