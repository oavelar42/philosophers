/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:58:13 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/20 22:34:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	time_die(t_data *p, size_t *count)
{
	pthread_mutex_lock(&(p->locked));
	if (!p->some_died && !p->philo[*count].ate && !p->philo[*count].last_eat
			&& (get_time() - p->philo[*count].last_eat) >=p->time_to_die)
	{
		printf(RED"[%ld] Philosopher's %d died\n", get_time()
				- p->base_time, p->num_of_philos);
		p->some_died = 1;
		pthread_mutex_unlock(&(p->locked));
		pthread_mutex_unlock(&(p->die));
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

/*void	init_global(t_data *global)
{
	int	count;

	global->base_time = get_time();
	global->monitor_flag = 0;
	global->mutex_id = malloc(sizeof(pthread_mutex_t) * global->num_of_philos);
	count = -1;
	while (++count < global->num_of_philos)
		pthread_mutex_init(&(global->mutex_id)[count], NULL);
	global->fork = malloc(sizeof(int) * global->num_of_philos);
	memset(global->fork, -1, global->num_of_philos);
	global->thread_id = malloc(sizeof(pthread_t) * global->num_of_philos);
}
void	init_philo(t_data *global, t_philo **philo)
{
	int	count;

	count = -1;
	*philo = malloc(sizeof(t_philo) * global->num_of_philos);
	while (++count < global->num_of_philos)
	{
		(*philo)[count].number = count;
		(*philo)[count].last_eat = get_time();
		(*philo)[count].eat_cnt = 0;
		if (count == 0)
			(*philo)[count].left_fork = global->num_of_philos - 1;
		else
			(*philo)[count].left_fork = count - 1;
		(*philo)[count].right_fork = count;
		(*philo)[count].data = global;
	}
}

void	mutex_destroy(t_data *global)
{
	int	count;

	count = -1;
	while (++count < global->num_of_philos)
	{
		usleep(10);
		pthread_mutex_destroy(&(global->mutex_id)[count]);
	}
	usleep(10);
}*/
