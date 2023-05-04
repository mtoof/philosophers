/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:59:27 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/04 12:54:57 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->tr[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].print);
		pthread_mutex_destroy(&data->philo[i].eaten);
		i++;
	}
	pthread_mutex_destroy(&data->finish);
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->modify_t);
	free(data->tr);
	free(data->fork);
	return (0);
}
