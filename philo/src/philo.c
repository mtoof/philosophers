/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/18 12:08:11 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	pthread_t		*tr;
	int				i;


	if (ac < 5 || ac > 6)
	{
		args_error(ac, av, 0);
		return (1);
	}
	if (check_digit(av) != 1)
		args_error(ac, av, 1);
	else
	{
		i = 0;
		data_init(&data, av, ac);
		init_mutex(&data);
	}
	return (0);
}
