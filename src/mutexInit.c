#include "philo.h"

void	general_init(t_general	*gen, char **str)
{
	gen->philos_count = ft_atoi(str[1]);
	gen->time_die = ft_atoi(str[2]);
	if (str[5])
		gen->max_eat = ft_atoi(str[5]);
	else
		gen->max_eat = -1;
	gen->die = 0;
	gen->philos = (t_philo *)malloc(sizeof(t_philo) * gen->philos_count);
	gen->fork = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * gen->philos_count);
	pthread_mutex_init(&gen->mutex_write, NULL);
	pthread_mutex_init(&gen->mutex_die, NULL);
}

void	pilos_init(t_general	*gen, char **str)
{
	int	i;

	i = 0;
	while (i < gen->philos_count)
	{
		gen->philos[i].id = i + 1;
		gen->philos[i].last_eat = 0;
		gen->philos[i].time_eat = ft_atoi(str[3]);
		gen->philos[i].time_sleep = ft_atoi(str[4]);
		gen->philos[i].count_must_eat = 0;
		gen->philos[i].die = &(gen->die);
		gen->philos[i].mutex_write = &(gen->mutex_write);
		gen->philos[i].mutex_die = &(gen->mutex_die);
		pthread_mutex_init(&(gen->philos[i].mutex_eat), NULL);
		pthread_mutex_init(&(gen->philos[i].mutex_last_eat), NULL);
		i++;
	}
}

void	fork_init(t_general	*gen)
{
	int	i;

	i = 0;
	while (i < gen->philos_count)
	{
		pthread_mutex_init(&(gen->fork[i]), NULL);
		i++;
	}
	i = 0;
	while (i < gen->philos_count)
	{
		if (i == gen->philos_count - 1)
		{
			gen->philos[i].mutex_left = &(gen->fork[i]);
			gen->philos[i].mutex_right = &(gen->fork[0]);
		}
		else
		{
			gen->philos[i].mutex_left = &(gen->fork[i]);
			gen->philos[i].mutex_right = &(gen->fork[i + 1]);
		}
		i++;
	}
}
