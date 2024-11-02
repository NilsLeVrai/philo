/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/02 18:45:04 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_death(t_philo *philo)
{
	mutex_safe(&philo->global->mutex_dead, LOCK);
	if (time_n(philo->global) - philo->last_meal > \
		philo->global->time_to_die)
	{
		print_info(philo->global, DEAD);
		return (1);
	}
	mutex_safe(&philo->global->mutex_dead, UNLOCK);
	philo->global->loop = 0;
	return (0);
}

/* 
	print_info(philo->global, FORKING);
	print_info(philo->global, EATING);
	print_info(philo->global, SLEEPING);
	print_info(philo->global, THINKING);
	print_info(philo->global, DEAD);
 */

void	print_info(t_global *global, t_state info)
{
	t_philo	*philo;

	philo = global->philo;
	mutex_safe(&global->mutex_print, LOCK);
	if (global->loop == 0)
	{
		mutex_safe(&global->mutex_print, UNLOCK);
		return ;
	}
	if (info == DEAD)
		printf(RED"%ld %d %s\n"RESET, time_n(global), philo->philo_id, DIE);
	else if (info == FORKING)
		printf(YELLOW"%ld %d %s\n"RESET, time_n(global), philo->philo_id, FORK);
	else if (info == EATING)
		printf(MAGENTA"%ld %d %s\n"RESET, time_n(global), philo->philo_id, EAT);
	else if (info == SLEEPING)
		printf(CYAN"%ld %d %s\n"RESET, time_n(global), philo->philo_id, SLEEP);
	else if (info == THINKING)
		printf(GREEN"%ld %d %s\n"RESET, time_n(global), philo->philo_id, THINK);
	mutex_safe(&global->mutex_print, UNLOCK);
}

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->philo_id % 2)
		usleep(100);
	while (1)
	{
		mutex_safe(&philo->left_fork, LOCK);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
		mutex_safe(&philo->left_fork, UNLOCK);
	}
	return (NULL);
}
