/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/28 16:45:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_info(t_global *global, char *info)
{
	mutex_safe(&global->mutex_print, LOCK);
	printf("%lu %d %s\n", get_current_time() - global->start_time, global->philo->philo_id, info);
	mutex_safe(&global->mutex_print, UNLOCK);
}

long get_current_time(void)
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*routine(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)argv;
	if (philo->philo_id % 2)
		usleep(100);
	return (NULL);
}
