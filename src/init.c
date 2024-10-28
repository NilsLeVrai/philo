/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:46:09 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/28 16:13:00 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int init_philo2(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->number_of_philosophers - 1)
	{
		global->philo[i].right_fork = &global->philo[i + 1].left_fork;
		i++;
	}
	global->philo[i].right_fork = &global->philo[0].left_fork;
	global->start_time = get_current_time();
	i = 0;
	while (i < global->number_of_philosophers)
	{
		if (pthread_create(&global->philo[i].thread_id, NULL, &routine, &global->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < global->number_of_philosophers)
	{
		if (pthread_join(global->philo[i].thread_id, NULL))
			return (1);
		i++;
	}
	return (0);
}

int init_philo(t_global *global)
{
	int i;

	i = 0;
	global->philo = malloc(sizeof(t_philo) * global->number_of_philosophers);
	if (!global->philo)
		return (1);
	if (pthread_mutex_init(&global->mutex_print, NULL))
		return (1);
	if (pthread_mutex_init(&global->mutex_dead, NULL))
		return (1);
	while (i < global->number_of_philosophers)
	{
		global->philo[i].philo_id = i + 1;
		global->philo[i].last_meal = 0;
		global->philo[i].meal_count = 0;
		global->philo[i].thread_id = 0;
		if (pthread_mutex_init(&global->philo[i].left_fork, NULL))
			return (1);
		global->philo[i].global = global;
		i++;
	}
	init_philo2(global);
	return (0);
}

int	init_global(char **argv, t_global *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->loop = ft_atoi(argv[5]);
	else
		philo->loop = -1;
	return (0);
}