/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:05 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/16 16:21:36 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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



typedef struct s_philo
{
	int	id;
	int	state;
	int	foods;
}				t_philo;

typedef struct	s_table
{
	t_fork	*f;
	t_philo	*p;
	t_info	info;
}				t_table;

/* ************************************************************************** */
/*                            BIBLIOTECAS.H                                   */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

/* ************************************************************************** */
/*                     PROTOTYPE OF FUNTION                                   */
/* ************************************************************************** */

#endif
