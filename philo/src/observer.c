/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/03 18:06:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->data->finish);
	if (flag == 1)
	{
		philo->data->eaten_enough = 1;
		pthread_mutex_unlock(&philo->data->finish);
		return (1);
	}
	if (philo->data->eaten_enough)
	{
		pthread_mutex_unlock(&philo->data->finish);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->finish);
	return (0);
}

int	died(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].eaten);
		if ((get_time() - data->philo[i].last_meal) >= data->death_time)
		{
			if (data->philo_num == 1)
			{
				pthread_mutex_unlock(&data->fork[data->philo[i].id - 1]);
				pthread_mutex_unlock(&data->fork[data->philo[i].id
					% (data->philo_num)]);
			}
			print_msg(data->start_time, &data->philo[i], "died");
			checker(data->philo, 1);
			pthread_mutex_unlock(&data->philo[i].eaten);
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].eaten);
		i++;
		usleep(100);
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
			pthread_mutex_lock(&data->philo[i].eaten);
			if (data->philo[i].finished == 0)
				finish_result = 0;
			pthread_mutex_unlock(&data->philo[i].eaten);
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
	int	flag;

	flag = 1;
	while (flag)
	{
		if (died(data) || eaten(data))
			flag = 0;
	}
	join_destroy(data);
}
