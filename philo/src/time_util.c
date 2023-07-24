/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:12:39 by mtoof             #+#    #+#             */
/*   Updated: 2023/07/24 17:02:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static unsigned long long	get_current_time_micro(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (((unsigned long long)current_time.tv_sec * 1000000ULL) + \
	current_time.tv_usec);
}

void	ft_usleep(t_philo *philo, u_int64_t time)
{
	u_int64_t	loop;
	int			wait_time;

	if (philo->data->philo_num <= 10)
		wait_time = 10;
	else
		wait_time = 500;
	loop = get_current_time_micro() + (time * 1000);
	while (!(checker(philo, 0)) && (get_current_time_micro() < loop))
		usleep(wait_time);
}
