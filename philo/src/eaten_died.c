/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaten_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/26 18:05:30 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eaten_died_check(t_philo *philo, t_data *data)
{
	int	i;
	int	finish_result;

	i = 0;
	finish_result = 1;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->eaten);
		if (philo[i].finish == 0)
			finish_result = 0;
		pthread_mutex_unlock(&data->eaten);
		i++;
	}
	if (finish_result == 1)
	{
		printf("\tall eaten enough!\n");
		i = -1;
		while (++i < data->philo_num)
		{
			pthread_mutex_unlock(&data->fork[philo[i].id - 1]);
			pthread_mutex_unlock(&data->fork[philo[i].id % data->philo_num]);
		}
		return (0);
	}
	i = 0;
	usleep(500);
	return (1);
}
