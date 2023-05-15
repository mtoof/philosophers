/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:27:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/15 22:30:38 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *msg)
{
	u_int64_t	real_time;

	pthread_mutex_lock(&philo->data->print);
	if (!(checker(philo, 0)))
	{
		real_time = get_time();
		printf("%ld %d %s\n", real_time - philo->data->start_time, philo->id,
			msg);
	}
	pthread_mutex_unlock(&philo->data->print);
}
