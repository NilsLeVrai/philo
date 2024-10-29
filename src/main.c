/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/29 15:23:32 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* static void test(t_global *philo)
{
	int i;

	i = 10;
	(void)philo;
	printf(YELLOW "philo_id %d has taken a fork\n" RESET, i);
	printf(MAGENTA "philo_id %d is eating\n" RESET, i);
	printf(CYAN "philo_id %d is sleeping\n" RESET, i);
	printf(GREEN "philo_id %d is thinking\n" RESET, i);
	printf(RED "Temps %d died\n" RESET, i);
	printf("" RESET);
} */


int	main(int argc, char **argv)
{
	t_global	*global;
	int		i;

	i = 0;
	check_errors(argc, argv);
	global = malloc(sizeof(t_global));
	if (!global)
	{
		ft_putstr_fd("Malloc failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (init_global(argv, global))
	{
		ft_putstr_fd("Parsing failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	//test(global);
	i = init_philo(global);
	routine(global);
	destroy_and_free(global);
	//printf("-------------BITE------------\n");
}

/*
chopper le temps
temps = temps ecoule depuis le debut du programme
last_eat important pour voir si le philo est alvie ou dead in the head
eat_count 


chaque philo cree sa fork de droite
prend en pointeur la fourchette de gauche

*/
