/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/28 17:55:12 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_info(t_global *global, char *info)
{
	mutex_safe(&global->mutex_print, LOCK);
	printf("%lu %d %s\n", get_current_time() - global->start_time, global->philo->philo_id, info);
	mutex_safe(&global->mutex_print, UNLOCK);
}

void	*routine(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)argv;
	if (philo->philo_id % 2)
		usleep(100);
	while (1)
	{
		
	}
	return (NULL);
}
