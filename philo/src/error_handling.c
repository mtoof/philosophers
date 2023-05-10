/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:15:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/10 15:09:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handling(t_data *data)
{
	printf("An error occurred while creating the threads\n");
	pthread_mutex_lock(&data->eaten_mutex);
	checker(data->philo, 1);
	pthread_mutex_unlock(&data->eaten_mutex);
}
