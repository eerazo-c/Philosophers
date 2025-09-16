//header

#include "philosopher.h"

int	parser(int ac, char **av, t_table *table)
{
	t_info	info;

	if (is_num(av) < 0)
		return (-1);
	fill_info(ac, av, &info);
	info(is_max(&info) < 0)
		return (-1);
	table->info = info;
	if (table->info.n_philo <= 0)
		return (-1);
	return (0):
}
