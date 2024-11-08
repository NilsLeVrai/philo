/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:03:58 by niabraha          #+#    #+#             */
/*   Updated: 2024/11/06 14:54:31 by niabraha         ###   ########.fr       */
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

typedef struct s_global_data	t_global;
typedef struct s_philo			t_philo;

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
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				loop;
	unsigned long	start_time;
	int				end_of_simulation;
	pthread_mutex_t	mutex_dead; // control access to death
	pthread_mutex_t	mutex_print; // control access to print
}	t_global;

typedef struct s_philo
{
	int				philo_id;
	unsigned long	last_meal;
	int				current_meal_count;
	int				is_full;
	pthread_t		thread_id;
	pthread_mutex_t	fork_lock;
	int				fork;
	t_global		*global;
	t_philo			*next;
}	t_philo;

//check

int		check_death(t_philo *philo);
int		check_full(t_philo *philo);
int		check_print(t_philo *philo);
int		check_starvation(t_philo *philo);
void	print_info(t_philo *philo, t_state info);

//errors

void	check_errors(int argc, char **argv);

//init

int		init_everything(t_global *global, t_philo **philo);
int		init_global(char **argv, t_global *global);
int		init_philo(t_global *global, t_philo *philo, int i);
int		pthread_safe(t_philo *philo, t_info info);
void	mutex_safe(pthread_mutex_t *mutex, t_info info);

//libft_functions

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

//routine

int		ft_eat(t_philo *philo);
int		ft_eat_even(t_philo *philo);
int		ft_eat_odd(t_philo *philo);
int		ft_fork(t_philo *philo, pthread_mutex_t *fork_lock, int *fork);
int		ft_sleep_and_think(t_philo *philo);

//main

void	*routine(void *argv);

//utils

int		ft_usleep_dead(unsigned long time, t_philo *philo);
int		ft_usleep_eat(unsigned long time, t_philo *philo);
long	get_current_time(void);
long	get_elapsed_time(t_global *global);
void	destroy_and_free(t_global *global, t_philo **philo);

#endif