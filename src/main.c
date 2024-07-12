/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:11 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/28 14:56:13 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine()
{
	printf("Little test.\n");
	sleep(3);
	printf("end\n");
}

int	main(int argc, char **argv)
{
/* 	if (argc == 5)
		philo(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]), \
		ft_atoi(argv[4]));
	else
		error_message(); */
	(void)argc;
	(void)argv;
	pthread_t	t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
