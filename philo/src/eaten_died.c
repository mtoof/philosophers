/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eaten_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/24 18:44:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eaten_died_check(pthread_t *tr, t_data *data)
{
	int	i;
	// int	j;

	// j = 0;
	i = 0;
	(void)tr;
	while(1)
	{
		pthread_mutex_lock(&data->lock);
		if (data->philo[i].data->finish == data->philo_num)
		{
			printf("data->philo[%d] has finished = %d\n", i, data->philo[i].data->finish);
			// join_destroy(tr, *data);
			// pthread_join(tr[i], NULL);
			// while (j < data->philo_num)
			// {
			// 	pthread_mutex_destroy(&data->fork[j]);
			// 	j++;
			// }
			// pthread_mutex_destroy(&data->print);
			// pthread_mutex_destroy(&data->lock);
			// if (data->fork)
			// 	free(data->fork);
			// if (data->philo)
			// 	free(data->philo);
			// if (tr)
			// 	free(tr);
			// printf("data->philo[%d] has finished %d\n", data->finish);
			pthread_mutex_unlock(&data->lock);
			return ;
		}
		i = (i + 1) % data->philo_num;
		usleep(500);
	}
}
