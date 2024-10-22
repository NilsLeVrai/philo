/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:46:09 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/22 15:06:03 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_global(t_global *global)
{
	int i;

	i = 0;
	printf("number_of_philosophers = %d\n", global->number_of_philosophers);
	while (i < global->number_of_philosophers)
	{
		global->philo[i].philo_id = i + 1;
		printf("le i: %d\n", i);
		global->philo[i].last_meal = 0;
		global->philo[i].meal_count = 0;
		global->philo[i].thread_id = 0;
		global->philo[i].left_fork = &global->forks[i];
		global->philo[i].right_fork = &global->forks[(i + 1) % global->number_of_philosophers];
		global->philo[i].global = global;
		i++;
	}
	return (0);
}

int	init_philo(char **argv, t_global *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
	philo->forks = malloc(sizeof(int) * philo->number_of_philosophers);
	if (!philo->forks)
	{
		ft_putstr_fd("Malloc failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}