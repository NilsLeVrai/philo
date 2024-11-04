/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/04 15:40:29 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_global	global;
	t_philo		*philo;

	philo = NULL;
	check_errors(argc, argv);
	if (init_global(argv, &global) == 1)
	{
		ft_putstr_fd("Malloc failed.\n", 2);
		exit(EXIT_FAILURE); // fonction pour tout free
	}
	if (init_everything(&global, &philo) == 1)
	{
		ft_putstr_fd("Malloc failed.\n", 2);
		exit(EXIT_FAILURE); // fonction pour tout free
	}
	destroy_and_free(&global, philo);
}
