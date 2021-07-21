/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:27 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 13:50:52 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_my_atoi(const char *str)
{
	long	count;
	long	neg;
	long	ret;

	count = 0;
	neg = 1;
	ret = 0;
	while (str[count] == '\f' || str[count] == '\t' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			neg *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		ret = (ret * 10) + (str[count] - 48);
		count++;
	}
	return (ret * neg);
}

unsigned int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(unsigned int delay)
{
	unsigned int	init;

	init = get_time();
	while ((get_time() - init) < delay)
		usleep(delay / 10);
}

void	clean_free(t_data *data)
{
	size_t	count;

	if (data->philo && data->num_of_philos > 0)
	{
		count = 0;
		while (count < data->num_of_philos)
		{
			pthread_mutex_destroy(&(data->fork[count]));
			count++;
		}
		free(data->fork);
		free(data->philo);
		pthread_mutex_destroy(&(data->die));
		pthread_mutex_destroy(&(data->locked));
		pthread_mutex_destroy(&(data->write));
	}
}
