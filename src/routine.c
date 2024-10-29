/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/29 15:30:17 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_death(t_philo *philo)
{
	mutex_safe(&philo->global->mutex_dead, LOCK);
	if (get_elapsed_time(philo->global) - philo->last_meal > philo->global->time_to_die)
	{
		print_info(philo->global, DEAD);
		return (1);
	}
	mutex_safe(&philo->global->mutex_dead, UNLOCK);
	philo->global->loop = 0;
	return (0);
}

void print_info(t_global *global, t_state info)
{
	mutex_safe(&global->mutex_print, LOCK);
	if (global->loop == 0)
	{
		mutex_safe(&global->mutex_print, UNLOCK);
		return ;
	}
	if (info == DEAD)
		printf(RED "%ld %d %s\n" RESET, get_elapsed_time(global), global->philo->philo_id, EAT);
	else if (info == FORKING)
		printf(YELLOW "%ld %d %s\n" RESET, get_elapsed_time(global), global->philo->philo_id, FORK);
	else if (info == EATING)
		printf(MAGENTA "%ld %d %s\n" RESET, get_elapsed_time(global), global->philo->philo_id, EAT);
	else if (info == SLEEPING)
		printf(CYAN "%ld %d %s\n" RESET, get_elapsed_time(global), global->philo->philo_id, SLEEP);
	else if (info == THINKING)
		printf(GREEN "%ld %d %s\n" RESET, get_elapsed_time(global), global->philo->philo_id, THINK);
	mutex_safe(&global->mutex_print, UNLOCK);
}

void	*routine(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)argv;
	printf("philo_id %d\n", philo->philo_id);
	if (philo->philo_id % 2)
		usleep(100);
	printf("----BITE----\n");
	while (!philo->global->loop)
	{
		mutex_safe(&philo->left_fork, LOCK);
		print_info(philo->global, FORKING);
		print_info(philo->global, EATING);
/* 		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo); */
		mutex_safe(&philo->left_fork, UNLOCK);
	}
	return (NULL);
}
