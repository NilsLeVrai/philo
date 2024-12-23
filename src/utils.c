/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:35:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/06 15:04:02 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep_eat(unsigned long time, t_philo *philo)
{
	unsigned long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time)
	{
		if (check_death(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

int	ft_usleep_dead(unsigned long time, t_philo *philo)
{
	unsigned long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time)
	{
		if (check_death(philo))
			return (1);
		if (check_starvation(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

long	get_elapsed_time(t_global *global)
{
	struct timeval	time;
	unsigned long	start_time;

	start_time = global->start_time;
	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start_time);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	destroy_and_free(t_global *global, t_philo **philo)
{
	int	i;

	i = -1;
	if (!*philo)
		return ;
	while (++i < global->number_of_philosophers - 1)
		mutex_safe(&(*philo)[i].fork_lock, DESTROY);
	mutex_safe(&(*philo)[i].fork_lock, DESTROY);
	mutex_safe(&global->mutex_dead, DESTROY);
	free(*philo);
}
