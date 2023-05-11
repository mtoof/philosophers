/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:15:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/11 15:53:38 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handling(t_data *data, int flag)
{
	if (flag == 1)
		printf("An error occurred during init data\n");
	if (flag == 2)
	{
		printf("An error occurred while creating the threads\n");
		pthread_mutex_lock(&data->eaten_mutex);
		checker(data->philo, 1);
		pthread_mutex_unlock(&data->eaten_mutex);
	}
}
