/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:05 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/23 20:19:10 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                            BIBLIOTECAS.H                                   */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <time.h>

/* ************************************************************************** */
/*                                 MACROS                                    */
/* ************************************************************************** */

# define SATISFIED 1
# define UNSATISFIED 0
# define AUX_MUTEX 4
# define STR_EAT "\033[0;34mEating 🍝\033[0m"
# define EATING 3
# define STR_SLEEP "\033[0;31mSleeping 😴\033[0m"
# define SLEEPING 2
# define STR_THINK "\033[0;33mThinking 🤔\033[0m"
# define THINKING 1
# define STR_FORK "Take both forks 🍴\033[0m"
# define STR_FORK2 "Relase both forks 🍴\033[0m"
# define STR_DIE "Dying 💀\033[0m"

/* ************************************************************************** */
/*                                 STRUCTS                                   */
/* ************************************************************************** */

typedef pthread_mutex_t	t_fork;

typedef	struct	s_info
{
	long	n_philo;
	long	time2_die;
	long	time2_eat;
	long	time2_sleep;
	long	max_eat;
	long	*end;
	t_fork	*starvation;
	t_fork	*printor;
	t_fork	*time;
	t_fork	*pleased;
}				t_info;

typedef struct s_philo
{
	int			id;
	int			state;
	int			foods;
	long		last_noodle;
	pthread_t	thread_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_info		info;
}				t_philo;

typedef struct	s_table
{
	t_fork	*f;
	t_philo	*p;
	t_info	info;
}				t_table;

/* ************************************************************************** */
/*                     PROTOTYPE OF FUNTION                                   */
/* ************************************************************************** */

//parser
int	parser(int ac, char **av, t_table *table);
//time
time_t get_mstime(void);

//playful
void	*mutex_fork(void *arg);
void	set_state(t_philo *p, char *state);

//init
void	ft_usleep(int ms);
int	everyone_eat(t_philo *p);
int	remember_die(t_philo *p);
int	init_philo(t_table *table);
int	init_mutex(t_table *table);
int	init_thread(t_table *table);

long	ft_atol(const char *str);
int	delete_all(t_table *table, int j);
#endif
