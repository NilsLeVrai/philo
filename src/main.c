/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/23 16:21:38 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long get_current_time(void)
{
	static long start_time;
	time_t temp_time;
	struct timeval current_time;

	start_time = 0;
	temp_time = 0;
	if (gettimeofday(&current_time, NULL))
	{
		printf("Error: gettimeofday failed.\n");
		exit(EXIT_FAILURE);
	}
	temp_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (temp_time - start_time);
}

static void test(t_global *philo)
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
}

/*
global = valeurs des arguments
philo = valeus propres a chaque philo
*/

int	main(int argc, char **argv)
{
	t_global	*global;
	int		i;

	i = 0;
	get_current_time();
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
	test(global);
	i = init_philo(global);
	//printf("-------------BITE------------\n");
	//ft_routine(argv);
}

/*
chopper le temps
temps = temps ecoule depuis le debut du programme
last_eat important pour voir si le philo est alvie ou dead in the head
eat_count 


chaque philo cree sa fork de droite
prend en pointeur la fourchette de gauche

*/
