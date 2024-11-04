/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:59:47 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 16:43:11 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_print(t_philo *philo)
{
	if (check_death(philo) == 0)
	{
		mutex_safe(&philo->global->mutex_print, UNLOCK);
		return (0);
	}
	if (philo->global->end_of_simulation == 1)
	{
		printf("END OF SIMULATION\n");
		return (1);
	}
	return (0);
}

int	check_starvation(t_philo *philo)
{
	if (get_starting_time() - philo->last_meal > philo->global->time_to_die)
	{
		if (philo->global->end_of_simulation == 0)
			print_info(philo, DEAD);
		mutex_safe(&philo->global->mutex_dead, LOCK);
		philo->global->end_of_simulation = 1;
		mutex_safe(&philo->global->mutex_dead, UNLOCK);
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	mutex_safe(&philo->global->mutex_dead, LOCK);
	if (philo->global->end_of_simulation == 1)
	{
		mutex_safe(&philo->global->mutex_dead, UNLOCK);
		return (1);
	}
	mutex_safe(&philo->global->mutex_dead, UNLOCK);
	return (0);
}

int	check_full(t_philo *philo)
{
	if (philo->global->loop != -1 && \
		philo->current_meal_count == philo->global->loop)
	{
		philo->is_full = 1;
		return (1);
	}
	return (0);
}
