/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:27:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/20 14:40:17 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	realtime(unsigned long time)
{
	unsigned long	realtime;

	realtime = get_time() - time;
	return (realtime);
}

void	print_msg(unsigned long time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", realtime(time), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	usleep(100);
}
