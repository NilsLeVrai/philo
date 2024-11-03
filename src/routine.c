/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/03 23:36:24 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_eaten_in_time(int time_to_eat, t_global *global)
{
	unsigned long	start_time;

	start_time = get_starting_time();
	if (get_starting_time() - start_time < time_to_eat)
	{
		if (check_death(global) == 1)
			return (1);
		usleep(100);
	}
	return (0);
}
{
	
	return (1);
}

int	check_death(t_philo *philo)
{
	mutex_safe(&philo->global->mutex_dead, LOCK);
	if (get_elapsed_time(philo->global) - philo->last_meal > \
		philo->global->time_to_die)
	{
		print_info(philo->global, DEAD);
		return (1);
	}
	mutex_safe(&philo->global->mutex_dead, UNLOCK);
	//
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
/*	if (global->loop == 0)
	{
		mutex_safe(&global->mutex_print, UNLOCK);
		return ;
	}*/
	if (info == DEAD)
		printf(RED"%ld %d %s\n"RESET, get_elapsed_time(global), philo->philo_id, DIE);
	else if (info == FORKING)
		printf(YELLOW"%ld %d %s\n"RESET, get_elapsed_time(global), philo->philo_id, FORK);
	else if (info == EATING)
		printf(MAGENTA"%ld %d %s\n"RESET, get_elapsed_time(global), philo->philo_id, EAT);
	else if (info == SLEEPING)
		printf(CYAN"%ld %d %s\n"RESET, get_elapsed_time(global), philo->philo_id, SLEEP);
	else if (info == THINKING)
		printf(GREEN"%ld %d %s\n"RESET, get_elapsed_time(global), philo->philo_id, THINK);
	mutex_safe(&global->mutex_print, UNLOCK);
}

int eat_even(t_philo *philo)
{
	if (check_all_philos_ate == 1)
		return (1);
	printf_info(philo->global, EATING);
	philo->last_meal = get_starting_time();
	if (check_eaten_in_time(philo->global->time_to_eat, philo->global) == 1)
		return (1);
	mutex_safe(philo->left_fork, UNLOCK);
	mutex_safe(philo->right_fork, UNLOCK);
	
	return (0);
}

int ft_eat(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
	return (0);
}

int ft_fork(t_philo *philo)
{
	while (1)
	{
		if (check_death(philo) == 0 || check_all_philos_ate(philo->global) == 1)
			return (1);
		mutex_safe(philo->left_fork, LOCK);
		print_info(philo->global, FORKING);
		mutex_safe(philo->right_fork, LOCK);
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
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
	return (NULL);
}
