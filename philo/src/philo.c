/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/26 18:07:54 by mtoof            ###   ########.fr       */
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
		ft_usleep(1);
	}
}

int	join_destroy(pthread_t	*tr, t_data data)
{
	int	i;

	i = 0;
	while (i < data.philo_num)
	{
		pthread_join(tr[i], NULL);
		i++;
	}
	i = -1;
	while (++i < data.philo_num)
	{
		pthread_mutex_destroy(&data.fork[i]);
	}
	pthread_mutex_destroy(&data.lock);
	pthread_mutex_destroy(&data.print);
	pthread_mutex_destroy(&data.eaten);
	usleep(500);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	*tr;

	if (check_args(ac, av) == -1)
		return (1);
	data_init(&data, av, ac);
	init_mutex(&data);
	tr = malloc(sizeof(pthread_t) * data.philo_num);
	thread_create(tr, data);
	// eaten_died_check(data.philo, &data);
	while (data.j < data.philo_num)
		usleep(500);
	if (data.j < data.philo_num)
	{
		join_destroy(tr, data);
		free(data.philo);
		free(data.fork);
		free(tr);
		printf("got here\n");
	}
	return (0);
}
