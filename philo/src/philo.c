/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/21 15:12:53 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_create(pthread_t	*tr, t_data data)
{
	int	i;

	i = 0;
	while (i < data.philo_num)
	{
		if (pthread_create(&tr[i], NULL, &routine, &data.philo[i]))
			return ;
		i++;
		usleep(1);
	}
}

void	join_destroy(pthread_t	*tr, t_data data)
{
	int	i;

	i = 0;
	while (i < data.philo_num)
	{
		pthread_join(tr[i], NULL);
		i++;
	}
	i = 0;
	while (i < data.philo_num)
	{
		pthread_mutex_destroy(&data.fork[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	*tr;

	if (check_args(ac, av) == -1)
		return (1);
	else
	{
		data_init(&data, av, ac);
		init_mutex(&data);
		tr = malloc(sizeof(pthread_t) * data.philo_num);
		thread_create(tr, data);
		join_destroy(tr, data);
	}
	return (0);
}
