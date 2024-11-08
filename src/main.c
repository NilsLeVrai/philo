/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/06 15:13:26 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	print_info(philo, THINKING);
	if (philo->philo_id % 2 == 0)
		ft_usleep_eat(5, philo);
	while (1)
	{
		if (ft_fork(philo, &philo->fork_lock, &philo->fork))
			return (NULL);
		if (ft_fork(philo, &philo->next->fork_lock, &philo->next->fork))
			return (NULL);
		if (ft_eat(philo))
			return (NULL);
		if (ft_sleep_and_think(philo))
			return (NULL);
	}
	return (NULL);
}

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
	if (philo->global->end_of_simulation == 1)
		printf("END OF SIMULATION\n");
	destroy_and_free(&global, &philo);
}
