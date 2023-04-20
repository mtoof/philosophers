/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:36:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/20 14:28:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alloc_philo_data(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	while (i < data->philo_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].data = data;
		i++;
	}
}

void	alloc_mutex(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_num);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
}

void	data_init(t_data *data, char **av, int ac)
{
	data->philo_num = (int)atoi(av[1]);
	data->death_time = (u_int64_t)atoi(av[2]);
	data->eat_time = (u_int64_t)atoi(av[3]);
	data->sleep_time = (u_int64_t)atoi(av[4]);
	if (ac == 6)
		data->meal_num = (int)atoi(av[5]);
	else
		data->meal_num = -1;
	data->start_time = get_time();
	alloc_philo_data(data);
	alloc_mutex(data);
}
