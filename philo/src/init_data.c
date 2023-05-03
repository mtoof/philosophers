/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:36:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/03 16:01:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_philo_data(t_data *data)
{
	int	i;

	data->tr = malloc(sizeof(pthread_t) * data->philo_num);
	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philo || !data->tr)
		return (-1);
	i = -1;
	while (++i < data->philo_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].finished = 0;
		data->philo[i].status = 0;
		data->philo[i].start = &data->start;
		data->philo[i].last_meal = data->start_time;
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

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&data->philo[i].print, NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&data->philo[i].eaten, NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&data->philo[i].lastmeal_mutex, NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&data->finish, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->start, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->modify_t, NULL) != 0)
		return (-1);
	return (0);
}

int	data_init(t_data *data, char **av, int ac)
{
	data->philo_num = ft_atol(av[1]);
	data->death_time = ft_atol(av[2]);
	data->eat_time = ft_atol(av[3]);
	data->sleep_time = ft_atol(av[4]);
	data->eaten_enough = 0;
	data->created = 0;
	data->start_time = get_time();
	if (ac == 6)
		data->meal_num = (int)ft_atol(av[5]);
	else
		data->meal_num = -1;
	if (alloc_philo_data(data) != 0)
		return (-1);
	if (alloc_mutex(data) != 0)
		return (-1);
	return (0);
}
