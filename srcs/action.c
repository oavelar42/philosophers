/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:59:06 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/21 00:15:27 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_fork(t_philo *p)
{
	size_t	forks;

	forks = (p->philo_id + 1) % p->data->num_of_philos;
	pthread_mutex_lock(&(p->data->fork[p->philo_id]));
	printf(MAG"[%ld] Philosopher's %d has taken a fork\n", get_time()
			- p->data->must_eat, p->philo_id);
	if (p->data->num_of_philos == 1)
	{
		sleep(200);
		pthread_mutex_unlock(&(p->data->fork[p->philo_id]));
		pthread_exit(0);
	}
	pthread_mutex_lock(&(p->data->fork[forks]));
	printf(MAG"[%ld] Philosopher's %d has taken a fork\n", get_time()
			- p->data->must_eat, p->philo_id);

	/*if (p->number % 2 == 1)
		usleep(300);
	take_fork(p, p->left_fork, p->right_fork, p->number);
	if (p->data->fork)
		printf(MAG"[%ld] Philosopher's %d has taken a fork\n", get_time()
			- p->data->base_time, p->number + 1);*/
}

static void	philo_eat(t_philo *p)
{
	printf(YEL"[%ld] Philosopher's %d is eating\n", get_time()
			- p->data->must_eat, p->philo_id);
	p->ate = 1;
	p->last_eat = get_time();
	(p->eat_count)++;
	pthread_mutex_unlock(&(p->data->locked));
	if (p->data->philo_eat > 0 && p->eat_count >= p->data->philo_eat)
	{
		pthread_mutex_unlock(&(p->data->fork[p->philo_id]));
		pthread_mutex_unlock(&(p->data->fork[(p->philo_id + 1) % p->data->num_of_philos]));
		p->data->must_eat++;
		p->data->must_eat = 1;
		if (p->data->must_eat >= p->data->num_of_philos)
		{
			p->data->some_died = 1;
			pthread_mutex_lock(&(p->data->write));
			printf("Philosophers satisfaded!!\n");
			pthread_mutex_unlock(&(p->data->write));
		}
		pthread_mutex_unlock(&(p->data->locked));
		pthread_exit(0);
	}
	pthread_mutex_unlock(&(p->data->locked));
	usleep(200);

	/*if (p->data->fork[p->left_fork] == p->number
		&& p->data->fork[p->right_fork] == p->number)
	{
		p->last_eat = get_time();
		printf(YEL"[%ld] Philosopher's %d is eating\n", get_time()
			- p->data->base_time, p->number + 1);
		p->eat_cnt++;
	}
	sleep_time(p->data->time_to_eat);*/
}

void	philo_sleep(t_philo *p)
{
	printf(GRE"[%ld] Philosopher's %d is sleeping\n", get_time()
		- p->data->base_time, p->number + 1);
	other_fork(p, p->right_fork, p->left_fork);
	sleep_time(p->data->time_to_sleep);
}

void	philo_think(t_philo *p)
{
	printf(BLU"[%ld] Philosopher's %d is thinking\n", get_time()
		- p->data->base_time, p->number + 1);
}

void	*routine_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->philo_id % 2)
		usleep(200);
	while (1)
	{
		philo_fork(philo);
		philo_eat(philo);
		other_fork(philo);
		printf(BLU"[%ld] Philosopher's %d is thinking\n", get_time()
		- philo->data->base_time, philo->philo_id);
		if (philo->data->some_died)
			pthread_exit(0);
	}
	pthread_exit(0);
}
