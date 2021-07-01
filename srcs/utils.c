/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:27 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/01 15:59:16 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long long	ft_my_atoi(const char *s)
{
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
}

long long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000L + time.tv_usec / 1000L));    
}

void	sleep_time(long long delay)
{
	long long end;

	end = get_time() + delay;
	while (end > get_time())
		usleep(100);
}