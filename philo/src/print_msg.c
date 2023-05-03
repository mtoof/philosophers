/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:27:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/03 15:29:14 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(u_int64_t time, t_philo *philo, char *msg)
{
	u_int64_t	real_time;

	real_time = get_time() - time;
	if (!(checker(philo, 0)))
	{
		pthread_mutex_lock(&philo->print);
		printf("%llu %d %s\n", real_time, philo->id, msg);
		pthread_mutex_unlock(&philo->print);
	}
}
	