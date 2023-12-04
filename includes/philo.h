/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:36:15 by vacsargs          #+#    #+#             */
/*   Updated: 2023/08/02 19:14:45 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

typedef void	*(*t_phtread_help)(void *);

typedef struct s_philo
{
	int				id;
	int				last_eat;
	int				time_eat;
	int				time_sleep;
	int				count_must_eat;
	int				*die;
	pthread_t		philo;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	*mutex_write;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_die;
}t_philo;

typedef struct s_general
{
	int				die;
	int				max_eat;
	int				time_die;
	int				philos_count;
	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_die;
}t_general;

int				main(int argc, char **argv);
char			**ft_split(char const *s, char c);
long			ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			general_init(t_general	*gen, char **str);
void			pilos_init(t_general	*gen, char **str);
void			fork_init(t_general	*gen);
void			ft_create(t_general	*gen);
int				pilo_die(t_philo *philo);
void			ft_usleep(unsigned long sleap, t_philo	*philo);
long long int	get_time(void);
int				pilo_live(t_general	*gen);
int				max_eat(t_general	*gen);
void			destroy_prog(t_general	*gen);

#endif