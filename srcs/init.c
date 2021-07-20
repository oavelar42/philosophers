/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:31 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/20 22:41:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	init_all(t_data *data, char **av, int ac)
{
	data->philo = NULL;
	if (!init_arg(data, av, ac))
		return (0);
	if (!init_philo(data))
		return (0);
	if (!init_mutex(data))
		return (0);
	return (1);
}