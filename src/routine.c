/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/05 15:33:38 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int ft_usleep_eat(unsigned long time, t_philo *philo)
{
	unsigned long start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time)
	{
		if (check_death(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

static int ft_usleep_dead(unsigned long time, t_philo *philo)
{
	unsigned long start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time)
	{
		if (check_death(philo) || check_starvation(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

static int	ft_sleep_and_think(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, SLEEPING);
	if (ft_usleep_dead(philo->global->time_to_sleep, philo))
		return (1);
	print_info(philo, THINKING);
	return (0);
}

static int	ft_eat_odd(t_philo *philo)
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

static int	ft_eat_even(t_philo *philo)
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

static int	ft_eat(t_philo *philo)
{
	if (philo->philo_id % 2)
		ft_eat_even(philo);
	else
		ft_eat_odd(philo);
	return (0);
}

static int	ft_fork(t_philo *philo, pthread_mutex_t *mutex, int *fork)
{
	while (1)
	{
		if (check_death(philo) || check_starvation(philo) || check_full(philo))
			return (1);
		mutex_safe(&philo->fork_lock, LOCK);
		if (*fork)
		{
			*fork = 0;
			print_info(philo, FORKING);
			mutex_safe(mutex, UNLOCK);
			return (0);
		}
		mutex_safe(&philo->fork_lock, UNLOCK);
	}
}

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->philo_id % 2)
		usleep(5);
	while (1)
	{
		if (ft_fork(philo, &philo->fork_lock, &philo->fork))
			break ;
		if (ft_fork(philo, &philo->next->fork_lock, &philo->next->fork))
			break ;
		if (ft_eat(philo))
			break ;
		if (ft_sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
