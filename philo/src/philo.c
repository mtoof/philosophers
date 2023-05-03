/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:55 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tr[i], NULL, &routine, &data->philo[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	join_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->tr[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].print);
		pthread_mutex_destroy(&data->philo[i].eaten);
		i++;
	}
	pthread_mutex_destroy(&data->finish);
	pthread_mutex_destroy(&data->start);
	free(data->tr);
	free(data->fork);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) == -1)
		return (1);
	data_init(&data, av, ac);
	init_mutex(&data);
	if (thread_create(&data) != 0)
		return (0);
	observer(&data);
	return (0);
}
