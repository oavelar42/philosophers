/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:58:13 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/24 14:27:17 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	msg_die(t_philo *p)
{
	printf(RED"[%ld] Philosopher's  %lu died\n", get_time()
		- p->data->init_time, p->philo_id + 1);
}

static void	time_die(t_data *p, size_t *count)
{
	pthread_mutex_lock(&(p->locked));
	if (!p->some_died && !p->philo[*count].ate && !p->philo[*count].must_eat
		&& (get_time() - p->philo[*count].last_eat) >= p->time_to_die)
	{
		pthread_mutex_unlock(&(p->die));
		msg_die(p->philo);
		if (p->time_to_die)
			exit(EXIT_SUCCESS);
		p->some_died = 1;
		pthread_mutex_unlock(&(p->locked));
		pthread_exit(0);
	}
	if (p->some_died)
	{
		pthread_mutex_unlock(&(p->locked));
		pthread_mutex_unlock(&(p->die));
		pthread_exit(0);
	}
	(*count)++;
	if (*count >= p->num_of_philos && !p->some_died)
		*count = 0;
	pthread_mutex_unlock(&(p->locked));
}

void	*ft_die(void *philo)
{
	t_data	*p;
	size_t	count;

	p = (t_data *)philo;
	pthread_mutex_lock(&(p->die));
	count = 0;
	while (count < p->num_of_philos)
	{
		time_die(p, &count);
		usleep(100);
	}
	return ((void *)0);
}
