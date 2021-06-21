/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:58:13 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/21 17:45:57 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void parse_init2(t_philo **input, int b, int *a, char **av)
{
    (*input)[b].number_of_philo = ft_my_atoi(av[(*a)++]);
    (*input)[b].time_to_die = ft_my_atoi(av[(*a)++]);
    (*input)[b].time_to_eat = ft_my_atoi(av[(*a)++]);
    (*input)[b].time_to_sleep = ft_my_atoi(av[(*a)++]);
    (*input)[b].live = true;
    (*input)[b].last_eat_time = get_time();
    (*input)[b].meals = 0;
    (*input)[b].time = get_time();
}

int parse_init(t_philo **input, int ac, char **av)
{
    int     a;
    int     b;
    t_philo *in;

    in = *input;
    in = (t_philo *)malloc(sizeof(t_philo) * ft_my_atoi(av[1]));
    if (!in)
        return (printf("ERROR...memory error\n"));
    b = 0;
    while (b < ft_my_atoi(av[1]))
    {
        a = 1;
        parse_init2(&in, b, &a, av);
        if (av[b] && a < ac)
        {
            in[b].end_eat = true;
            in[b].end_eat_amount = ft_my_atoi(av[a++]);
        }
        if (in[b]. number_of_philo <= 0 || in[b].time_to_die <= 0
            || in[b].time_to_eat <= 0 || in[b].time_to_sleep <= 0
            || (in[b].end_eat && in[b].end_eat_amount <= 0))
            return (printf("ERROR...input value.\n"));
        b++;
    }
    *input = in;
    return (1);
}
