/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:27 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/18 12:09:09 by oavelar          ###   ########.fr       */
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

int	ft_my_atoi(const char *str)
{
	int	holder;
	int	sign;

	holder = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		holder = holder * 10 + *str - '0';
		str++;
	}
	return (holder * sign);
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

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	sleep_time(long long delay)
{
	long long	end;

	end = delay + get_time();
	while (end > get_time())
		usleep(100);
}
