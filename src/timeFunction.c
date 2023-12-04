#include "philo.h"

long long int	get_time(void)
{
	static unsigned long long	start;
	static int					count = 0;
	struct timeval				as;

	gettimeofday(&as, NULL);
	if (count == 0)
	{
		start = (as.tv_sec * 1000 + as.tv_usec / 1000);
		count++;
	}
	return ((as.tv_sec * 1000 + as.tv_usec / 1000) - start);
}

void	ft_usleep(unsigned long sleap, t_philo	*philo)
{
	unsigned long	value;

	(void)philo;
	value = get_time();
	usleep(950);
	while (get_time() - value < sleap)
		usleep(10);
}
