/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:34:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/21 17:51:40 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo             *init;
    //pthread_t           *pth;
    //pthread_mutex_t     *mute;

    //pth = NULL;
    //mute = NULL;
    //g_stop = false;
    //g_meals = 0;
    if (ac < 5 || ac > 6)
        return (printf("ERROR...wrong arguments.\n"));
    if (ft_my_atoi(av[1]) < 2)
        return (printf("ERROR...philosophers alone.\n"));
    if (!parse_init(&init, ac, av))
        return (printf("ERROR...incorrect information.\n"));
    return (0);
}