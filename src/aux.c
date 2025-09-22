//header

#include "philosophers.h"

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time_value();
	while (get_time_value() - time < ms)
		usleep(100);
}
