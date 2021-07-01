/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:34:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/01 15:15:51 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_data *global)
{
	t_philo	*philo;
	int		count;

	count = -1;
	init_philo(global, &philo);
	init_global(global);
	while (++count < global->num_of_philos)
	{
		pthread_create(&(global->thread_id)[count],
		NULL, pthread_routine, &philo[count]);
		pthread_detach(global->thread_id[count]);
	}
	while (1)
	{
		if (time_eat_monitor(philo, global))
			break ;
		if (time_die_monitor(philo, global))
			break ;
	}
	mutex_detroy(global);
	return (0);
}

void	init_data(t_data global, char *av[])
{
	global.num_of_philos = ft_my_atoi(av[1]);
	global.time_to_die = ft_my_atoi(av[2]);
	global.time_to_eat = ft_my_atoi(av[3]);
	global.time_to_sleep = ft_my_atoi(av[3]);
	global.time_must_eat = 0;
	global.time_must_eat_flag = 0;
}

int main(int ac, char **av)
{
	t_data global;

	if (ac != 5 && ac != 6)
		printf(RED"Error, wrong arguments!\n");
	else
	{
		init_data(global, av);
		if (ac == 6)
			global.time_must_eat = ft_my_atoi(av[5]);
		philo(&global);
	}
	return (0);
}