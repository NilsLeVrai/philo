/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 16:33:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_sleep_and_think(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, SLEEPING);
	//ft_usleep
	print_info(philo, THINKING);
	return (0);
}

static int	ft_eat_even(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, EATING);
	philo->last_meal = get_starting_time();
	//ft_usleep
	mutex_safe(&philo->fork_lock, LOCK);
	mutex_safe(&philo->next->fork_lock, LOCK);
	philo->fork = 1;
	philo->next->fork = 1;
	mutex_safe(&philo->next->fork_lock, UNLOCK);
	mutex_safe(&philo->fork_lock, UNLOCK);
	philo->current_meal_count++;
	return (0);
}

static int	ft_eat_odd(t_philo *philo)
{
	if (check_full(philo))
		return (1);
	print_info(philo, EATING);
	philo->last_meal = get_starting_time();
	//ft_usleep
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
		ft_eat_odd(philo);
	else
		ft_eat_even(philo);
	return (0);
}

static int	ft_fork(t_philo *philo)
{
	while (1)
	{
		if (check_death(philo) || check_starvation(philo) || check_full(philo))
			return (1);
		mutex_safe(&philo->fork_lock, LOCK);
		if (philo->fork == 0)
		{
			philo->fork = 1;
			print_info(philo, FORKING);
			mutex_safe(&philo->fork_lock, UNLOCK);
			return (0);
		}
		mutex_safe(&philo->fork_lock, UNLOCK);
	}
}

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	while (1)
	{
		if (ft_fork(philo))
			break ;
		if (ft_fork(philo->next))
			break ;
		if (ft_eat(philo))
			break ;
		if (ft_sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
