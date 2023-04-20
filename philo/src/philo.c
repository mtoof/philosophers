/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/20 14:49:34 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
		print_msg(philo->data->start_time, philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->fork[philo->id
			% (philo->data->philo_num)]);
		print_msg(philo->data->start_time, philo, "has taken a fork");
		print_msg(philo->data->start_time, philo, "is eating");
		ft_usleep(philo->data->eat_time);
		pthread_mutex_unlock(&philo->data->fork[philo->id
			% (philo->data->philo_num)]);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		print_msg(philo->data->start_time, philo, "is sleeping");
		ft_usleep(philo->data->sleep_time);
		print_msg(philo->data->start_time, philo, "is thinking");
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	*tr;
	int			i;

	if (ac < 5 || ac > 6)
	{
		args_error(ac, av, 0);
		return (1);
	}
	if (check_digit(av) != 1)
	{
		args_error(ac, av, 1);
		return (1);
	}
	else
	{
		i = 0;
		data_init(&data, av, ac);
		init_mutex(&data);
		tr = malloc(sizeof(pthread_t) * data.philo_num);
		while (i < data.philo_num)
		{
			pthread_create(&tr[i], NULL, &routine, &data.philo[i]);
			usleep(100);
			i++;
		}
		i = 0;
		while (i < data.philo_num)
		{
			pthread_join(tr[i], NULL);
			i++;
		}
		i = 0;
		while (i < data.philo_num)
		{
			pthread_mutex_destroy(&data.fork[i]);
			i++;
		}
	}
	return (0);
}
