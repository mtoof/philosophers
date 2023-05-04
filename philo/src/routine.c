/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/04 17:00:11 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_msg(philo->start_time, philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	print_msg(philo->start_time, philo, "has taken a fork");
	print_msg(philo->start_time, philo, "is eating");
	ft_usleep(philo, philo->data->eat_time);
	pthread_mutex_lock(&philo->eaten);
	if (philo->eat_count >= philo->data->meal_num)
		philo->finished = 1;
	philo->eat_count++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eaten);
	pthread_mutex_unlock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
}

static void	wait_for_all(t_philo *philo, int *i)
{
	pthread_mutex_lock(philo->start);
	while ((*i) < philo->data->philo_num)
	{
		if (philo->status == 0)
		{
			philo->status = 1;
			(*i)++;
		}
		pthread_mutex_unlock(philo->start);
	}
}

void	*routine(void *data)
{
	t_philo			*philo;
	static int		i;

	philo = (t_philo *)data;
	wait_for_all(philo, &i);
	philo->start_time = get_time();
	if (philo->id % 2 == 0)
		ft_usleep(philo, philo->data->eat_time);
	while (1)
	{
		if ((checker(philo, 0)))
			return (NULL);
		take_fork(philo);
		print_msg(philo->start_time, philo, "is sleeping");
		ft_usleep(philo, philo->data->sleep_time);
		print_msg(philo->start_time, philo, "is thinking");
	}
	return (NULL);
}
