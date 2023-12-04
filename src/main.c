#include "philo.h"

int	has_zero(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0)
		{
			printf("Error:argument is invalid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		if (ft_strlen(str[i]) == 0)
		{
			printf("Error:argument is invalid\n");
			return (0);
		}
		j = 0;
		while (str[i][j])
		{
			if (j == 0 && (str[i][j] == '+'))
				j++;
			if ((str[i][j] < '0' || str[i][j] > '9'))
			{
				printf("Error:argument is invalid\n");
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_general	gen;

	get_time();
	if (argc == 5 || argc == 6)
	{
		if (check_valid(argv) == 0)
			return (0);
		if (has_zero(argv) == 0)
			return (0);
		general_init(&gen, argv);
		pilos_init(&gen, argv);
		fork_init(&gen);
		ft_create(&gen);
		destroy_prog(&gen);
	}
	else
	{
		printf("Error : Wrong number of arguments\n");
		return (0);
	}
}
