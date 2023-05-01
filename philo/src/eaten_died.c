/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaten_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/01 18:10:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->lmealt);
		if ((get_time() - data->philo[i].last_meal) >= data->death_time)
		{
			print_msg(data->start_time, &data->philo[i], "died");
			checker(data->philo, 1);
			pthread_mutex_unlock(&data->lmealt);
			return (1);
		}
		pthread_mutex_unlock(&data->lmealt);
		i++;
	}
	return (0);
}

int	eaten(t_data *data)
{
	int	i;
	int	finish_result;

	i = 0;
	finish_result = 1;
	if (data->meal_num != -1)
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->eaten);
			if (data->philo[i].finish == 0)
				finish_result = 0;
			pthread_mutex_unlock(&data->eaten);
			i++;
		}
		i = 0;
		if (finish_result == 1)
		{
			checker(data->philo, 1);
			return (1);
		}
	}
	return (0);
}

void	observer(t_data *data)
{
	while (!eaten(data) && !died(data))
	{
		continue ;
		usleep(10);
	}
	join_destroy(data);
}
