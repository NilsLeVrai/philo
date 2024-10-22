/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:13:24 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/22 12:42:26 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_outrange_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
		{
			ft_putstr_fd("Arguments are out of range.\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_not_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (argv[i][j] == '+' && j == 0)
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_putstr_fd("Arguments must be numbers.\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_errors(int argc, char **argv)
{
	check_args(argc);
	check_not_number(argc, argv);
	check_outrange_int(argc, argv);
}
