/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:46:09 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/02 19:00:38 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	time_n(t_global *global)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - global->start_time);
}

long	get_starting_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	init_philo2(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->number_of_philosophers - 1)
	{
		global->philo[i].right_fork = &global->philo[i + 1].left_fork;
		i++;
	}
	global->philo[i].right_fork = &global->philo[0].left_fork;
	global->start_time = get_starting_time();
	i = 0;
	while (i < global->number_of_philosophers)
	{
		if (pthread_create(&global->philo[i].thread_id, NULL, &routine, &global->philo[i]))
		{
			global->check_error = 1;
			printf("Error creating threads.\n");
			destroy_and_free(global);
		}
		i++;
	}
	i = 0;
	while (i < global->number_of_philosophers)
	{
		if (pthread_join(global->philo[i].thread_id, NULL))
		{
			global->check_error = 2;
			printf("Error joining threads.\n");
			destroy_and_free(global);
		}
		i++;
	}
}

int	init_philo(t_global *global)
{
	int	i;

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
	philo->check_error = 0;
	if (argv[5])
		philo->loop = ft_atoi(argv[5]);
	else
		philo->loop = 1;
	return (0);
}
