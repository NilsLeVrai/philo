/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 17:15:43 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_global	global;
	t_philo		*philo;

	philo = NULL;
	check_errors(argc, argv);
	if (init_global(argv, &global))
		exit(EXIT_FAILURE);
	if (init_everything(&global, &philo))
		exit(EXIT_FAILURE);
	destroy_and_free(&global, &philo);
}
