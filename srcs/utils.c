/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:27 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 11:48:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}*/

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

/*{
	long long	res;
	long long	check;
	int			sign;

	res = 0;
	check = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s && (*s == 43 || *s == 45))
	{
		if (*s == 45)
			sign = -1;
		s++;
	}
	while ('0' <= *s && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		if (check > res && sign == 1)
			return (9223372036854775807);
		else if (check > res && sign == -1)
			return (-9223372036854775807);
		s++;
	}
	return (res * sign);
}*/

unsigned int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(long long delay)
{
	long long	end;

	end = delay + get_time();
	while (end > get_time())
		usleep(100);
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
