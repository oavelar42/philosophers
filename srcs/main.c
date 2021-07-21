/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:34:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 11:13:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	philo(t_data *global)
{
	size_t count;

	if (pthread_create(&(global->th_death), NULL, &ft_die, (void *)(global)))
		return (0);
	pthread_detach(global->th_death);
	count = -1;
	while (++count < global->num_of_philos)
	{
		if (pthread_create(&(global->philo[count].thread_id),
				NULL, &routine_philo, (void *)(&(global->philo[count]))))
		return (0);
	}
	count = -1;
	while (++count < global->num_of_philos)
		if (pthread_join(global->philo[count].thread_id, NULL))
			return (0);
	return (1);
	/*init_philo(global, &philo);
	init_global(global);
	while (++count < global->num_of_philos)
	{
		pthread_create(&(global->thread_id)[count],
			NULL, routine_philo, &philo[count]);
		pthread_detach(global->thread_id[count]);
	}
	while (1)
	{
		if (time_eat_monitor(philo, global))
			break ;
		if (time_die_monitor(philo, global))
			break ;
	}
	mutex_destroy(global);
	return (0);*/
}

int	main(int ac, char **av)
{
	t_data	global;

	if (ac < 5 || ac > 6)
		printf(RED"Error, wrong arguments!\n");
	if (!init_all(&global, av, ac))
	{
		clean_free(&global);
		printf(RED"We can't start , init error or memory leaks!\n");
	}
	if (!philo(&global))
	{
		clean_free(&global);
		printf(RED"Error , threads error!\n");
	}
	pthread_mutex_lock(&(global.die));
	pthread_mutex_unlock(&(global.die));
	usleep(10);
	clean_free(&global);
	return (0);
}
	/*else
	{
		global.num_of_philos = ft_my_atoi(av[1]);
		global.time_to_die = ft_my_atoi(av[2]);
		global.time_to_eat = ft_my_atoi(av[3]);
		global.time_to_sleep = ft_my_atoi(av[3]);
		global.time_must_eat = 0;
		global.time_must_eat_flag = 0;
		if (ac == 6)
			global.time_must_eat = ft_my_atoi(av[5]);
		philo(&global);
	}
	return (0);
}*/
