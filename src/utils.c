/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:35:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/02 18:45:13 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_and_free(t_global *global)
{
	int	i;

	i = 0;
	if (global->check_error == 1)
		printf("Error creating threads.\n");
	else if (global->check_error == 2)
		printf("Error joining threads.\n");
	while (i < global->number_of_philosophers)
	{
		pthread_mutex_destroy(&global->philo[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&global->mutex_print);
	pthread_mutex_destroy(&global->mutex_dead);
	free(global->philo);
}
