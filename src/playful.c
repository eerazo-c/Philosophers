//header
#include "philosophers.h"

static	void take_forks(t_philo *p, int i)
{
	if (i == 2)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
		set_state(p, STR_FORK);
	}
	else
	{	
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
		set_state(p, STR_FORK);
	}
}

void	*mutex_fork(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;
	if (p->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(p->info.starvation);
		if (*p->info.end != 0)
		{
			pthread_mutex_unlock(p->info.starvation);
			break ;
		}
		pthread_mutex_unlock(p->info.starvation);
		set_state(p, STR_THINK);
		if ((p->id % 2) == 0)
			take_forks(p, 2);
		else
			take_forks(p, 1);
		printf("HOLA, HASTA AQUI BIEN BEBE");
		//if (sleping(p))
			break;
	}
	return (NULL);
}
