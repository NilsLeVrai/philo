/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:58 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/23 16:16:11 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DIE "died"
# define THINK "is thinking"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef pthread_mutex_t	t_mutex;
typedef struct s_global_data t_global;

typedef struct s_forks
{
	int				fork_id; // si une fork a ete prise
	t_mutex			mutex_fork; //controler l'acces a la fork
}	t_forks;


typedef struct s_philo
{
	int				philo_id;
	long			last_meal;
	long			meal_count;
	pthread_t		thread_id;
	t_forks			*left_fork;
	t_forks			*right_fork;
	t_global		*global;
}	t_philo;

typedef struct s_global_data
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
	t_mutex			mutex;
	t_philo			*philo;
	t_forks			*forks;
}	t_global;

//errors

void	check_args(int argc);
void	check_errors(int argc, char **argv);
void	check_not_number(int argc, char **argv);
void	check_outrange_int(int argc, char **argv);

//init

int		init_philo(t_global *global);
int		init_global(char **argv, t_global *global);

//routine

void	ft_routine(char **argv);

//threads

void	philo(int a, int b, int c, int d);

//utils

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif