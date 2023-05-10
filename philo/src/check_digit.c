/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:41:09 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/10 18:40:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	args_error(int ac, char **av, int flag)
{
	if (ac < 5 && flag == 0)
	{
		printf("%s: Not Enough Arguments\n", av[0]);
		printf("%s: num_philos time_die time_eat"
			" time_sleep meal_number(optional)\n", av[0]);
	}
	else if (ac > 6 && flag == 0)
		printf("%s: Too many arguments\n", av[0]);
	else if (flag == 1)
	{
		printf("%s: Invalid arguments\n", av[0]);
	}
}

static int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				j++;
				if (av[i][j] == '\0')
					return (-1);
			}
			if (ft_isdigit(av[i][j]) == 1)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_positive(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) <= 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		args_error(ac, av, 0);
		return (-1);
	}
	if (check_digit(av) != 0)
	{
		args_error(ac, av, 1);
		return (-1);
	}
	if (check_positive(ac, av) != 0)
	{
		printf("Aguments must be > 0\n");
		return (-1);
	}
	return (0);
}
