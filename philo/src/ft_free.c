/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:59:27 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/10 16:26:13 by mtoof            ###   ########.fr       */
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
	free(data->fork);
	free(data->tr);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eaten_mutex);
	pthread_mutex_destroy(&data->finish_mutex);
	return (0);
}
