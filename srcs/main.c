/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:34:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 17:30:43 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	philo(t_data *global)
{
	size_t	count;

	if (pthread_create(&(global->death), NULL, &ft_die, (void *)(global)))
		return (0);
	pthread_detach(global->death);
	count = -1;
	while (++count < global->num_of_philos)
	{
		if (pthread_create(&(global->philo[count].thread),
				NULL, &routine_philo, (void *)(&(global->philo[count]))))
			return (0);
	}
	count = -1;
	while (++count < global->num_of_philos)
		if (pthread_join(global->philo[count].thread, NULL))
			return (0);
	return (1);
}

int	main(int ac, char const **av)
{
	t_data	global;

	if (ac < 5 || ac > 6)
		return (printf(RED"Error, wrong arguments!\n"));
	if (!init_all(&global, av, ac))
	{
		clean_free(&global);
		return (printf(RED"We can't start , init error or negative number!\n"));
	}
	if (!philo(&global))
	{
		clean_free(&global);
		return (printf(RED"Error , threads error!\n"));
	}
	pthread_mutex_lock(&(global.die));
	pthread_mutex_unlock(&(global.die));
	sleep_time(5);
	clean_free(&global);
	return (0);
}
