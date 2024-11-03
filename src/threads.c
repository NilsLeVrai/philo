/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:14:47 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/03 23:22:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int check_all_philos_ate(t_global *global)
{
	int i;

	i = 0;
	if (global->total_meal == -1)
		return (1);
	while (i < global->number_of_philosophers)
	{
		if (global->philo[i].current_meal_count < global->total_meal)
			return (0);
		i++;
	}
	return (1);
}

int loop_check(t_global *global)
{
	int i;

	i = 0;
	while (1)
	{
		if (check_all_philos_ate(global))
			break ;
		while (i < global->number_of_philosophers)
		{
			if (global->start_time - global->philo[i].last_meal > global->time_to_die)
			{
				print_info(global, DEAD);
				return (1);
			}
			usleep(250); //?
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
