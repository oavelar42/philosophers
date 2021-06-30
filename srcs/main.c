/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:34:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/30 21:48:33 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo				*init;
	pthread_t			*pth;
	pthread_mutex_t		*mute;

	pth = NULL;
	mute = NULL;
	//init = NULL;
	//init->data->stop = false;
	//init->data->meals = 0;
	if (ac < 5 || ac > 6)
		return (printf("ERROR...wrong arguments.\n"));
	if (ft_my_atoi(av[1]) < 2)
		return (printf("ERROR...philosophers alone.\n"));
	if (!parse_init(&init, ac, av))
		return (printf("ERROR...incorrect information.\n"));
	if (!init_mutex(init, &mute))
		return (printf("Error : No init mutex!\n"));
	if (!init_thread(init, &pth, &mute))
		return (printf("Error : No init thread!\n"));
	if (!init_process(init, &pth))
		return (printf("Error : process wrong.\n"));
	clear_program(&init, &mute, &pth);
	return (0);
}