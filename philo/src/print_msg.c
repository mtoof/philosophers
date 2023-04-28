/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:27:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/28 10:14:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	realtime(long long time)
{
	long long	realtime;

	realtime = get_time() - time;
	return (realtime);
}

void	print_msg(long long time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", realtime(time), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
}
	