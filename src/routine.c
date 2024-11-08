/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/06 14:48:23 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep_and_think(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, SLEEPING);
	if (ft_usleep_dead(philo->global->time_to_sleep, philo))
		return (1);
	print_info(philo, THINKING);
	return (0);
}

int	ft_eat_odd(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, EATING);
	philo->last_meal = get_current_time();
	if (ft_usleep_eat(philo->global->time_to_eat, philo))
		return (1);
	mutex_safe(&philo->fork_lock, LOCK);
	mutex_safe(&philo->next->fork_lock, LOCK);
	philo->fork = 1;
	philo->next->fork = 1;
	mutex_safe(&philo->next->fork_lock, UNLOCK);
	mutex_safe(&philo->fork_lock, UNLOCK);
	philo->current_meal_count++;
	return (0);
}

int	ft_eat_even(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, EATING);
	philo->last_meal = get_current_time();
	if (ft_usleep_eat(philo->global->time_to_eat, philo))
		return (1);
	mutex_safe(&philo->next->fork_lock, LOCK);
	mutex_safe(&philo->fork_lock, LOCK);
	philo->fork = 1;
	philo->next->fork = 1;
	mutex_safe(&philo->fork_lock, UNLOCK);
	mutex_safe(&philo->next->fork_lock, UNLOCK);
	philo->current_meal_count++;
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (philo->philo_id % 2)
		return (ft_eat_even(philo));
	else
		return (ft_eat_odd(philo));
	return (0);
}

int	ft_fork(t_philo *philo, pthread_mutex_t *fork_lock, int *fork)
{
	while (1)
	{
		if (check_death(philo) || check_starvation(philo) || check_full(philo))
			return (1);
		mutex_safe(fork_lock, LOCK);
		if (*fork)
		{
			*fork = 0;
			print_info(philo, FORKING);
			mutex_safe(fork_lock, UNLOCK);
			return (0);
		}
		mutex_safe(fork_lock, UNLOCK);
	}
}
