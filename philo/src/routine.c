/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/11 15:01:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	print_msg(philo, "has taken a fork");
	print_msg(philo, "is eating");
	ft_usleep(philo, philo->data->eat_time);
	pthread_mutex_lock(&philo->data->eaten_mutex);
	philo->eat_count++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->eaten_mutex);
	pthread_mutex_unlock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	print_msg(philo, "is sleeping");
	ft_usleep(philo, philo->data->sleep_time);
	print_msg(philo, "is thinking");
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_msg(philo, "is thinking");
	if (philo->id % 2 == 0)
		ft_usleep(philo, philo->data->eat_time);
	while (1)
	{
		if ((checker(philo, 0)))
			return (NULL);
		take_fork(philo);
	}
	return (NULL);
}
