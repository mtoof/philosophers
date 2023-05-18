/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/18 18:31:13 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(t_philo *philo, int exit_flag)
{
	pthread_mutex_lock(&philo->data->finish_mutex);
	if (exit_flag == 1)
	{
		philo->data->must_exit = 1;
		pthread_mutex_unlock(&philo->data->finish_mutex);
		return (1);
	}
	if (philo->data->must_exit)
	{
		pthread_mutex_unlock(&philo->data->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return (0);
}

static int	philo_num_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eaten_mutex);
	ft_usleep(philo, philo->data->death_time);
	if ((get_time() - philo->last_meal) >= philo->data->death_time)
	{
		print_msg(philo, "died");
		checker(philo->data->philo, 1);
		pthread_mutex_unlock(&philo->data->eaten_mutex);
	}
	pthread_mutex_unlock(&philo->data->fork[0]);
	pthread_mutex_unlock(&philo->data->fork[0]);
	pthread_mutex_unlock(&philo->data->eaten_mutex);
	return (1);
}

static int	died_eaten(t_philo *philo, int margin)
{
	pthread_mutex_lock(&philo->data->eaten_mutex);
	if ((get_time() - philo->last_meal) >= philo->data->death_time + margin)
	{
		print_msg(philo, "died");
		checker(philo->data->philo, 1);
		pthread_mutex_unlock(&philo->data->eaten_mutex);
		return (1);
	}
	else if (philo->data->meal_num > 0
		&& (philo->eat_count >= philo->data->meal_num))
	{
		philo->data->finished++;
		if (philo->data->finished >= philo->data->philo_num)
		{
			checker(philo->data->philo, 1);
			pthread_mutex_unlock(&philo->data->eaten_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->eaten_mutex);
	return (0);
}

void	observer(t_data *data)
{
	int	exit_flag;
	int	i;

	exit_flag = 1;
	while (exit_flag)
	{
		i = -1;
		data->finished = 0;
		while (++i < data->philo_num)
		{
			if (data->philo_num == 1)
			{
				philo_num_one(data->philo);
				exit_flag = 0;
			}
			else if (died_eaten(&data->philo[i], data->margin))
				exit_flag = 0;
		}
		if (data->philo_num > 150)
			ft_usleep(data->philo, 1);
		else
			usleep(500);
	}
	join_destroy(data);
}
