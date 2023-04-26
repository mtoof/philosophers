/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/26 17:55:02 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eaten);
	if (philo->eat_count >= philo->data->meal_num)
		philo->finish = 1;
	pthread_mutex_unlock(&philo->data->eaten);
	usleep(100);
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

void	*routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
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
		if (eaten_died_check(philo, philo->data) == 0)
			break ;
	}
	philo->data->j++;
	return (philo);
}
