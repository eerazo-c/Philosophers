/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:32:12 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/23 19:40:25 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static int	special_case(t_table *t)
{
	if (t->info.max_eat == 0)
	{
		printf("Every Philo is Satisfied 😋\n");
		return (-1);
	}
	else if (t->info.n_philo == 1)
	{
		printf("0 The philosopher [0] is %s\n", STR_THINK);
		ft_usleep(t->info.time2_die);
		printf("%li The philosopher [0] is %s\n", t->info.time2_die, STR_DIE);
		return (-1);
	}
	return (0);
}

int	delete_all(t_table *table, int j)
{
	int	i;

	i = -1;
	if (table->f)
	{
		while (++i < j)
			pthread_mutex_destroy(&table->f[i]);
		free(table->f);
		table->f = NULL;
	}
	if (table->p)
		free(table->p);
	return (-1);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 6 || ac == 5)
	{
		if (parser(ac, av, &table) < 0)
			printf("philo: invalid digit\n");
		else
		{
			if (special_case(&table) < 0)
				return (-1);
			if (init_mutex(&table) < 0)
				return (-1);
			if (init_philo(&table) < 0)
				return (-1);
			if (init_thread(&table) < 0)
				return (-1);
		}
	}
	else
		printf("philo: incorrect number of arguments\n");
	return (0);
}
