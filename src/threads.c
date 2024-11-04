/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:14:47 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 16:06:20 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_info(t_philo *philo, t_state info)
{
	t_global	*global;

	global = philo->global;
	mutex_safe(&philo->global->mutex_print, LOCK);
	if (check_death(philo) == 0)
	{
		mutex_safe(&philo->global->mutex_print, UNLOCK);
		return ;
	}
	if (philo->global->end_of_simulation == 1)
	{
		printf("END OF SIMULATION\n");
		return ;
	}
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
