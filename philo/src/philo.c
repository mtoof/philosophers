/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/07/24 19:12:12 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_create(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_micro() / 1000;
	while (i < data->philo_num)
	{
		data->philo[i].last_meal = data->start_time;
		if (pthread_create(&data->tr[i], NULL, &routine, &data->philo[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) == -1)
		return (-1);
	if (data_init(&data, av, ac) != 0)
	{
		error_handling(&data, 1);
		join_destroy(&data);
		return (-1);
	}
	if (thread_create(&data) != 0)
	{
		error_handling(&data, 2);
		join_destroy(&data);
		return (-1);
	}
	observer(&data);
	return (0);
}
