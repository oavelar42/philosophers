/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:31 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/01 16:04:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	init_thread(t_philo *in, pthread_t **ph2, pthread_mutex_t **mutx2)
{
	int			index;
	pthread_t	*ph;

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

int	init_mutex(t_philo *in, pthread_mutex_t **mutx2)
{
	int				index;
	pthread_mutex_t	*pth;

	(*mutx2 = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
		* in[0].number_of_philo));
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

void		clear_program(t_philo **in, pthread_mutex_t **mu2,
		pthread_t **ph2)
{
	int					index;
	int					end;

	index = 0;
	end = (*in)[index].number_of_philo;
	while (index < end)
		pthread_mutex_destroy(&(*mu2)[index++]);
	free((*mu2));
	free((*ph2));
	pthread_mutex_destroy((*in)->mutex_monitor);
	free((*in));
}*/