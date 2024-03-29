/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:36:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/07/24 19:11:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_philo_data(t_data *data)
{
	int	i;

	data->tr = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tr)
		return (-1);
	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philo)
		return (-1);
	i = -1;
	while (++i < data->philo_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].data = data;
	}
	return (0);
}

int	alloc_mutex(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->fork)
		return (-1);
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (-1);
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->eaten_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->finish_mutex, NULL) != 0)
		return (-1);
	return (0);
}

int	data_init(t_data *data, char **av, int ac)
{
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->must_exit = 0;
	data->start_time = get_time();
	data->finished = 0;
	if (ac == 6)
		data->meal_num = (int)ft_atoi(av[5]);
	else
		data->meal_num = -1;
	if (alloc_philo_data(data) != 0)
		return (-1);
	if (alloc_mutex(data) != 0)
		return (-1);
	if (init_mutex(data) != 0)
		return (-1);
	return (0);
}
