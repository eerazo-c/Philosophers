/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:23:05 by elerazo-          #+#    #+#             */
/*   Updated: 2025/07/30 19:46:01 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//# <biblioteca.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"

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
