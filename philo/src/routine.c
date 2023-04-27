/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/27 15:54:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eaten);
	if (philo->eat_count >= philo->data->meal_num)
		philo->finish = 1;
	pthread_mutex_unlock(&philo->data->eaten);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_msg(philo->data->start_time, philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	print_msg(philo->data->start_time, philo, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
}

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

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time);
	while (!checker(philo, 0))
	{
		take_fork(philo);
		print_msg(philo->data->start_time, philo, "is eating");
		philo->eat_count++;
		philo_eaten(philo);
		ft_usleep(philo->data->eat_time);
		put_fork(philo);
		print_msg(philo->data->start_time, philo, "is sleeping");
		ft_usleep(philo->data->sleep_time);
		print_msg(philo->data->start_time, philo, "is thinking");
		pthread_mutex_lock(&philo->data->lock);
		pthread_mutex_unlock(&philo->data->lock);
	}
	return (data);
}
