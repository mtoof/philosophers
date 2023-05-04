/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:27:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/04 16:59:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(u_int64_t time, t_philo *philo, char *msg)
{
	u_int64_t	real_time;

	if (!(checker(philo, 0)))
	{
		usleep(10);
		pthread_mutex_lock(&philo->print);
		real_time = get_time() - time;
		printf("%lld %d %s\n", real_time, philo->id, msg);
		pthread_mutex_unlock(&philo->print);
	}
}
	