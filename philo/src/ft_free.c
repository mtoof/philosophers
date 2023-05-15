/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:59:27 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/15 22:17:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->tr[i], NULL);
	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy(&data->fork[i]);
	if (data->fork)
		free(data->fork);
	if (data->tr)
		free(data->tr);
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->eaten_mutex);
	pthread_mutex_destroy(&data->finish_mutex);
	return (0);
}
