/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/18 18:34:47 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->data->fork[philo->id]);
	pthread_mutex_lock(&philo->data->fork[(philo->id + 1)
		% (philo->data->philo_num)]);
	printf("philo id = %d\n", philo->id);
	pthread_mutex_unlock(&philo->data->fork[(philo->id + 1)
		% (philo->data->philo_num)]);
	pthread_mutex_unlock(&philo->data->fork[philo->id]);
	printf("philo id = %d finished\n", philo->id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	*tr;
	int			i;

	if (ac < 5 || ac > 6)
	{
		args_error(ac, av, 0);
		return (1);
	}
	if (check_digit(av) != 1)
	{
		args_error(ac, av, 1);
		return (1);
	}
	else
	{
		i = 0;
		data_init(&data, av, ac);
		init_mutex(&data);
		tr = malloc(sizeof(pthread_t) * data.philo_num);
		while (i < data.philo_num)
		{
			pthread_create(&tr[i], NULL, &routine, &data.philo[i]);
			usleep(100);
			i++;
		}
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
	return (0);
}
