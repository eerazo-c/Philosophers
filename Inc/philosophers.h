/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:05 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/08 19:56:30 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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

//# <biblioteca.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
//# include "../library/printf/ft_printf.h"
//# include "../library/libft/libft.h"

//structura
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1_path;
	char	*cmd2_path;
	char	*path;
	char	**args;
	char	**envp;
	char	**cmd1_args;
	char	**cmd2_args;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	int		fd[2];
	int		doc[2];
	int		pid[2];
}				t_pipex;

//prototipo de funciones

#endif
