/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/01 18:21:17 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eaten(t_philo *philo)
{
	if (!checker(philo, 0))
	{
		pthread_mutex_lock(&philo->data->eaten);
		if (philo->eat_count >= philo->data->meal_num)
			philo->finish = 1;
		philo->eat_count++;
		pthread_mutex_unlock(&philo->data->eaten);
		pthread_mutex_lock(&philo->data->lmealt);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->data->lmealt);
	}
}

void	take_fork(t_philo *philo)
{
	if (!checker(philo, 0))
	{
		pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
		print_msg(philo->data->start_time, philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->fork[philo->id
			% (philo->data->philo_num)]);
		print_msg(philo->data->start_time, philo, "has taken a fork");
		print_msg(philo->data->start_time, philo, "is eating");
		ft_usleep(philo, philo->data->eat_time);
	}
}

void	put_fork(t_philo *philo)
{
	if (!checker(philo, 0))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->id
			% (philo->data->philo_num)]);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		print_msg(philo->data->start_time, philo, "is sleeping");
		ft_usleep(philo, philo->data->sleep_time);
		print_msg(philo->data->start_time, philo, "is thinking");
		pthread_mutex_lock(&philo->data->lock);
		pthread_mutex_unlock(&philo->data->lock);
	}
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
		ft_usleep(philo, philo->data->eat_time);
	while (!(checker(philo, 0)))
	{
		take_fork(philo);
		philo_eaten(philo);
		put_fork(philo);
	}
	return (data);
}
