/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:46:09 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 16:41:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	pthread_safe(t_philo *philo, t_info info)
{
	int	check;

	check = 0;
	if (info == CREATE)
	{
		check = pthread_create(&philo->thread_id, NULL, &routine, philo);
		if (check)
		{
			printf("Thread creation failed\n");
			return (1);
		}
	}
	else if (info == JOIN)
	{
		check = pthread_join(philo->thread_id, NULL);
		if (check)
		{
			printf("Thread joining failed\n");
			return (1);
		}
	}
	return (0);
}

void	mutex_safe(pthread_mutex_t *mutex, t_info info)
{
	int	check;

	check = 0;
	if (info == INIT)
		check = pthread_mutex_init(mutex, NULL);
	else if (info == LOCK)
		check = pthread_mutex_lock(mutex);
	else if (info == UNLOCK)
		check = pthread_mutex_unlock(mutex);
	else if (info == DESTROY)
		check = pthread_mutex_destroy(mutex);
	if (check)
	{
		printf("Mutex failed\n");
		exit(EXIT_FAILURE);
	}
}

int	init_philo(t_global *global, t_philo *philo, int i)
{
	philo[i].philo_id = i + 1;
	philo[i].global = global;
	philo[i].current_meal_count = 0;
	philo[i].last_meal = get_starting_time();
	philo[i].is_full = 0;
	philo[i].fork = 1;
	mutex_safe(&philo[i].fork_lock, INIT);
	if (global->number_of_philosophers - 1 == i)
		philo[i].next = &philo[0];
	else
		philo[i].next = &philo[i + 1];
	return (0);
}

int	init_everything(t_global *global, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * global->number_of_philosophers);
	if (!*philo)
		return (1);
	mutex_safe(&global->mutex_dead, INIT);
	mutex_safe(&global->mutex_print, INIT);
	global->start_time = get_starting_time();
	while (++i < global->number_of_philosophers)
		init_philo(global, *philo, i);
	i = -1;
	while (++i < global->number_of_philosophers)
	{
		if (pthread_safe(&(*philo)[i], CREATE))
			return (destroy_and_free(global, *philo), 1);
	}
	i = -1;
	while (++i < global->number_of_philosophers)
	{
		if (pthread_safe(&(*philo)[i], JOIN))
			return (destroy_and_free(global, *philo), 1);
	}
	return (0);
}

int	init_global(char **argv, t_global *global)
{
	global->number_of_philosophers = ft_atoi(argv[1]);
	global->time_to_die = ft_atoi(argv[2]);
	global->time_to_eat = ft_atoi(argv[3]);
	global->time_to_sleep = ft_atoi(argv[4]);
	global->end_of_simulation = 0;
	if (argv[5])
		global->loop = ft_atoi(argv[5]);
	else
		global->loop = -1;
	return (0);
}
