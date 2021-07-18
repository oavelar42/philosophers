/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:31 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/18 12:10:15 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_eat_monitor(t_philo *p, t_data *global)
{
	int			index;

	if (global->time_must_eat
		&& global->time_must_eat_flag == global->num_of_philos)
		return (1);
	index = -1;
	while (++index < global->num_of_philos)
	{
		if (p[index].eat_cnt == global->time_must_eat)
		{
			global->time_must_eat_flag++;
			p[index].eat_cnt++;
		}
	}
	return (0);
}

int	time_die_monitor(t_philo *p, t_data *global)
{
	int		index;
	int		time;

	index = -1;
	time = 0;
	while (++index < global->num_of_philos)
	{
		time = get_time() - p[index].last_eat;
		if (time >= global->time_to_die)
		{
			global->monitor_flag = 1;
			printf(RED"[%ld] Philosopher's %d died\n", get_time()
				- p->data->base_time, p->number);
			return (1);
		}
		if (p[index].eat_cnt == global->time_must_eat)
		{
			global->time_must_eat_flag++;
			p[index].eat_cnt++;
		}
	}
	return (0);
}
