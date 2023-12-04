#include "philo.h"

int	pilo_die(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(philo->mutex_die);
	i = *(philo->die);
	pthread_mutex_unlock(philo->mutex_die);
	return (i);
}

void	check_all_live(t_philo	*philo, char *str)
{
	pthread_mutex_lock(philo->mutex_write);
	if (pilo_die(philo) == 0)
		printf("[%d] : [%lld]  %s", philo->id, get_time(), str);
	pthread_mutex_unlock(philo->mutex_write);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_eat, philo);
	while (!pilo_die(philo))
	{	
		pthread_mutex_lock(philo->mutex_left);
		check_all_live(philo, "He picked up a fork from the left\n");
		pthread_mutex_lock(philo->mutex_right);
		check_all_live(philo, "He picked up a fork from the right\n");
		check_all_live(philo, "He started to eat\n");
		pthread_mutex_lock(&philo->mutex_last_eat);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->mutex_last_eat);
		ft_usleep(philo->time_eat, philo);
		pthread_mutex_lock(&philo->mutex_eat);
		philo->count_must_eat++;
		pthread_mutex_unlock(&philo->mutex_eat);
		pthread_mutex_unlock(philo->mutex_left);
		pthread_mutex_unlock(philo->mutex_right);
		check_all_live(philo, "He is sleeping\n");
		ft_usleep(philo->time_sleep, philo);
		check_all_live(philo, "He is thinking\n");
	}
	return (NULL);
}

void	ft_create(t_general	*gen)
{
	int	i;

	i = 0;
	while (i < gen->philos_count)
	{
		pthread_create(&gen->philos[i].philo, NULL,
			(t_phtread_help)routine, (&gen->philos[i]));
		i++;
	}
	i = 0;
	while (1)
	{
		if (pilo_live(gen) == 1 || max_eat(gen) == 1)
			break ;
	}
	while (i < gen->philos_count)
	{
		if (gen->philos_count != 1)
			pthread_join((gen->philos[i].philo), NULL);
		i++;
	}
}
