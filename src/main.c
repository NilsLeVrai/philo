/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/02 18:43:25 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_global	*global;
	int			i;

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
	i = init_philo(global);
	if (i)
	{
		ft_putstr_fd("Malloc failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	routine(global);
	destroy_and_free(global);
}

/*
chopper le temps
temps = temps ecoule depuis le debut du programme
last_eat important pour voir si le philo est alvie ou dead in the head
eat_count 


chaque philo cree sa fork de droite
prend en pointeur la fourchette de gauche

*/
