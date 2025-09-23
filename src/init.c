//header

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
			return(delete_all(table, philos + AUX_MUTEX)); 
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
	int i;
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
/*comprueba si el filosofo i ha muerto y marca end si corresponde*/

static int	check_starvation_and_handle(t_philo *p, int i)
{
	if (p[i].last_noodle + p[i].info.time2_die < get_mstime())
	{
		pthread_mutex_unlock(p->info.time);
		set_state(&p[i], STR_DIE);
		pthread_mutex_lock(p->info.starvation);
		*p[i].info.end = 1;
		pthread_mutex_unlock(p->info.starvation);
		return (-1);
	}
	pthread_mutex_unlock(p->info.time);
	return (0);
}

int	remember_die(t_philo *p)
{
	int	i;
	int n;

	i = 0;
	n = (int)p->info.n_philo;
	while (1)
	{
		if (everyone_eat(p) < 0)
			break ;
		pthread_mutex_lock(p->info.time);
		if (check_starvation_and_handle(p, i) < 0)
			break ;
		i++;
		if (i >= n)
			i = 0;
	}
	return (-1);
}


/* Inicializa los campos de un solo filósofo (para mantener init_philo corta) */
static void	init_philo_slot(t_table *table, int i, int philos)
{
	table->p[i].id = i;
	if (i != 0)
		table->p[i].left_fork = table->p[i - 1].right_fork;
	table->p[i].right_fork = table->f + i;
	table->p[i].foods = 0;
	table->p[i].state = UNSATISFIED;
	table->p[i].info = table->info;
	table->p[i].info.starvation = table->f + philos;
	table->p[i].info.printor = table->f + philos + 1;
	table->p[i].info.time = table->f + philos + 2;
	table->p[i].info.pleased = table->f + philos + 3;
	table->p[i].last_noodle = get_mstime();
}

int	init_philo(t_table *table)
{
	int	philos;
	int	i;

	philos = (int)table->info.n_philo;
	i = -1;
	table->p = malloc(sizeof(t_philo) * philos);
	if (!table->p)
		return (delete_all(table, philos + AUX_MUTEX));
	while (++i < philos)
		init_philo_slot(table, i, philos);
	table->p[0].left_fork = table->f + (philos - 1);
	return (0);
}

int	init_mutex(t_table *table)
{
	int	philos;
	int	i;
	int total;

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
