//header

#include "philosophers.h"

void	fill_info(int ac, char **av, t_info *info)
{
	info->n_philo = atol(av[1]); //aqui modificar al atol
	info->time2_die = atol(av[2]);
	info->time2_eat = atol(av[3]);
	info->time2_sleep = atol(av[4]);
	if (ac == 6)
		info->max_eat = atol(av[5]);
	else
		info->max_eat = -1; //revisar aqui
	info->end = malloc(sizeof(int) * 1);
	info->end[0] = 0;
}

int	is_num(char **num)
{
	int	i;
	int	j;

	i = 1;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (num[i][j] >= 48 && num[i][j] <= 57)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
/*
static	int is_max(t_info *data)
{
	if (!(data->n_philo ))
}
*/
int	parser(int ac, char **av, t_table *table)
{
	t_info	info;

	if (is_num(av) < 0)
		return (-1);
	fill_info(ac, av, &info);
//	info(is_max(&info) < 0); 
		return (-1);
	table->info = info;
	if (table->info.n_philo <= 0)
		return (-1);
	return (0);
}
