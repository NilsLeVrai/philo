/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:14:47 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/28 16:39:50 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void mutex_safe(pthread_mutex_t *mutex, t_info info)
{
	int check;

	check = 0;
	if (info == INIT)
		check = pthread_mutex_init(mutex, NULL);
	else if (info == LOCK)
		check = pthread_mutex_lock(mutex);
	else if (info == UNLOCK)
		check = pthread_mutex_unlock(mutex);
	else if (info == DESTROY)
		check = pthread_mutex_destroy(mutex);
	if (check)
	{
		printf("Mutex failed\n");
		exit(EXIT_FAILURE);
	}
}
