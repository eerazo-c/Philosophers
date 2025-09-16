/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:32:12 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/16 15:52:15 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static int	special_case(t_table *tab)
{
	if (tab->info.max_eat == 0)
	{
		printf("Every Philo is Satisfied 😋\n");
		return (-1);
	}
	else if (tab->info.num_philo == 1)
	{
		printf("0 The philosopher [0] is %s\n", STR_THINK);
		ft_usleep(tab->info.time2_die);
		printf("%li The philosopher [0] is %s\n", t->info.time2_die, STR_DIE);
		return (-1);
	}
}

int main(int ac, char **av)
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
			if (start_philo(&table) < 0)
				return (-1);
		}
	}
	else
		printf("philo: incorrect number of arguments\n");
	return (0);
}
