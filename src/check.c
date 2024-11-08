/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:59:47 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/06 15:13:00 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_info(t_philo *philo, t_state info)
{
	t_global	*global;

	global = philo->global;
	mutex_safe(&philo->global->mutex_print, LOCK);
	if (check_print(philo))
		return ;
	else if (info == DEAD)
		printf(RED"%ld %d %s\n"RESET, \
			get_elapsed_time(global), philo->philo_id, DIE);
	else if (info == FORKING)
		printf(YELLOW"%ld %d %s\n"RESET, \
			get_elapsed_time(global), philo->philo_id, FORK);
	else if (info == EATING)
		printf(MAGENTA"%ld %d %s\n"RESET, \
			get_elapsed_time(global), philo->philo_id, EAT);
	else if (info == SLEEPING)
		printf(CYAN"%ld %d %s\n"RESET, \
			get_elapsed_time(global), philo->philo_id, SLEEP);
	else if (info == THINKING)
		printf(GREEN"%ld %d %s\n"RESET, \
			get_elapsed_time(global), philo->philo_id, THINK);
	mutex_safe(&global->mutex_print, UNLOCK);
}

int	check_print(t_philo *philo)
{
	if (check_death(philo) == 0)
	{
		mutex_safe(&philo->global->mutex_print, UNLOCK);
		return (0);
	}
	return (0);
}

int	check_starvation(t_philo *philo)
{
	if (((get_current_time() - philo->last_meal)) >= philo->global->time_to_die)
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
		(philo->current_meal_count == philo->global->loop))
	{
		philo->is_full = 1;
		philo->global->end_of_simulation = 1;
		return (1);
	}
	return (0);
}
