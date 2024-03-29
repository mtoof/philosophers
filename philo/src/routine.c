/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/07/24 19:27:31 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_sleep(t_philo *philo)
{
	print_msg(philo, "is eating");
	pthread_mutex_lock(&philo->data->eaten_mutex);
	philo->eat_count++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->eaten_mutex);
	ft_usleep(philo, philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->fork[philo->id
		% (philo->data->philo_num)]);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	print_msg(philo, "is sleeping");
	ft_usleep(philo, philo->data->sleep_time);
	print_msg(philo, "is thinking");
}

static void	take_fork(t_philo *philo)
{
	if (!checker(philo, 0))
	{
		pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->fork[philo->id \
		% (philo->data->philo_num)]);
		print_msg(philo, "has taken a fork");
	}
	else
		return ;
	eat_sleep(philo);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, \
			"thinking");
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
