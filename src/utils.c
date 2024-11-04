/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:35:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 15:58:24 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_elapsed_time(t_global *global)
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

void	destroy_and_free(t_global *global, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < global->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].fork_lock);
		i++;
	}
	pthread_mutex_destroy(&global->mutex_print);
	pthread_mutex_destroy(&global->mutex_dead);
	free(philo);
	free(global);
}
