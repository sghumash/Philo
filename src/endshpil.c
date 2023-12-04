#include "philo.h"

void	destroy_prog(t_general	*gen)
{
	int	i;

	i = 0;
	while (i < gen->philos_count)
	{
		pthread_mutex_destroy(&gen->fork[i]);
		pthread_mutex_destroy(&gen->philos[i].mutex_eat);
		pthread_mutex_destroy(&gen->philos[i].mutex_last_eat);
		i++;
	}
	pthread_mutex_destroy(&gen->mutex_die);
	pthread_mutex_destroy(&gen->mutex_write);
	free(gen->philos);
	free(gen->fork);
}

int	pilo_live(t_general	*gen)
{
	int	i;

	i = 0;
	while (i < gen->philos_count)
	{
		pthread_mutex_lock(&gen->philos[i].mutex_last_eat);
		if (get_time() - gen->philos[i].last_eat > gen->time_die)
		{
			pthread_mutex_lock(gen->philos[i].mutex_write);
			printf("[%d] : [%lld] Died\n", gen->philos[i].id, get_time());
			pthread_mutex_unlock(gen->philos[i].mutex_write);
			pthread_mutex_lock(gen->philos[i].mutex_die);
			gen->die = 1;
			pthread_mutex_unlock(gen->philos[i].mutex_die);
			pthread_mutex_unlock(&gen->philos[i].mutex_last_eat);
			return (1);
		}
		pthread_mutex_unlock(&gen->philos[i].mutex_last_eat);
		i++;
	}
	return (0);
}

int	max_eat(t_general	*gen)
{
	int	i;

	i = 0;
	while (i < gen->philos_count && gen->max_eat != -1)
	{
		pthread_mutex_lock(&gen->philos[i].mutex_eat);
		if (gen->philos[i].count_must_eat >= gen->max_eat)
		{
			pthread_mutex_unlock(&gen->philos[i].mutex_eat);
			i++;
		}
		else
		{
			pthread_mutex_unlock(&gen->philos[i].mutex_eat);
			break ;
		}
	}
	if (i == gen->philos_count)
	{
		pthread_mutex_lock(&gen->mutex_die);
		gen->die = 1;
		pthread_mutex_unlock(&gen->mutex_die);
		return (1);
	}
	return (0);
}
