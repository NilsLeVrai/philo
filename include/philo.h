/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:58 by niabraha          #+#    #+#             */
/*   Updated: 2024/10/29 15:18:38 by niabraha         ###   ########.fr       */
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

typedef struct s_global_data t_global;
typedef struct s_philo t_philo;

typedef enum e_state
{
	FORKING,
	EATING,
	SLEEPING,
	DEAD,
	THINKING,
}	t_state;

typedef enum e_info
{
	INIT,
	CREATE,
	JOIN,
	LOCK,
	UNLOCK,
	DESTROY
}	t_info;

typedef struct s_global_data
{
	int				number_of_philosophers;
	int 			check_error;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	start_time;
	int				loop; // 0 = dead, 1 = alive
	pthread_mutex_t	mutex_print; // control access to print
	pthread_mutex_t	mutex_dead; // control access to death
	t_philo			*philo;
}	t_global;

typedef struct s_philo
{
	int				philo_id;
	unsigned long	last_meal;
	long			meal_count;
	pthread_t		thread_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_global		*global;
}	t_philo;


//errors

void	check_args(int argc);
void	check_errors(int argc, char **argv);
void	check_not_number(int argc, char **argv);
void	check_outrange_int(int argc, char **argv);

//init

int		init_global(char **argv, t_global *global);
int		init_philo(t_global *global);

//libft_functions

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

//routine

void	print_info(t_global *global, t_state info);
long	get_starting_time(void);
long	get_elapsed_time(t_global *global);
void	*routine(void *argv);
int 	check_death(t_philo *philo);

//threads

void	mutex_safe(pthread_mutex_t *mutex, t_info info);

//utils

void	destroy_and_free(t_global *global);

#endif