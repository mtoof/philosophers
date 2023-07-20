/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:12:39 by mtoof             #+#    #+#             */
/*   Updated: 2023/07/19 08:40:52 by mtoof            ###   ########.fr       */
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

	loop = get_current_time_micro() + (time * 1000);
	while (!(checker(philo, 0)) && (get_current_time_micro() < loop))
		usleep(10);
}
