/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:53:09 by elerazo-          #+#    #+#             */
/*   Updated: 2025/09/24 15:53:13 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	init_thread(t_table *table)
{
	t_philo	*p;
	int		philos;
	int		i;

	philos = (int)table->info.n_philo;
	p = table->p;
	i = -1;
	get_mstime();
	while (++i < philos)
	{
		if (pthread_create(&(p[i].thread_id), NULL, mutex_fork,
				&p[i]) != 0)
			return (delete_all(table, philos + AUX_MUTEX));
	}
	i = -1;
	remember_die(p);
	while (++i < philos)
	{
		if (pthread_join(p[i].thread_id, NULL) != 0)
			return (delete_all(table, philos + AUX_MUTEX));
	}
	return (0);
}

int	everyone_eat(t_philo *p)
{
	int	i;
	int	n;

	i = 0;
	n = (int)p->info.n_philo;
	pthread_mutex_lock(p->info.pleased);
	while (i < n && p[i].state == SATISFIED)
		i++;
	if (i == n)
	{
		pthread_mutex_unlock(p->info.pleased);
		printf("Every Philo is Satisfied 😋\n");
		return (-1);
	}
	pthread_mutex_unlock(p->info.pleased);
	return (0);
}

int	init_mutex(t_table *table)
{
	int	philos;
	int	i;
	int	total;

	philos = (int)table->info.n_philo;
	total = philos + AUX_MUTEX;
	table->f = malloc(sizeof(t_fork) * total);
	if (!table->f)
		return (delete_all(table, -1));
	i = 0;
	while (i < total)
	{
		if (pthread_mutex_init(&(table->f[i]), NULL) != 0)
			return (delete_all(table, i));
		i++;
	}
	return (0);
}
