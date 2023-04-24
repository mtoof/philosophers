/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/24 18:31:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eaten(t_philo *philo)
{
	if (philo->eat_count == philo->data->meal_num)
		philo->data->finish++;
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_msg(philo->data->start_time, philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	print_msg(philo->data->start_time, philo, "has taken a fork");
}

void	*routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->data->eaten);
		take_fork(philo);
		print_msg(philo->data->start_time, philo, "is eating");
		philo->eat_count++;
		philo_eaten(philo);
		ft_usleep(philo->data->eat_time);
		pthread_mutex_unlock(&philo->data->fork[philo->id
			% (philo->data->philo_num)]);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		print_msg(philo->data->start_time, philo, "is sleeping");
		ft_usleep(philo->data->sleep_time);
		print_msg(philo->data->start_time, philo, "is thinking");
		pthread_mutex_unlock(&philo->data->eaten);
	}
	return (NULL);
}
