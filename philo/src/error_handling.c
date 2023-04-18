/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:15:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/18 18:14:17 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_error(int ac, char **av, int flag)
{
	if (ac < 5 && flag == 0)
	{
		printf("%s: Not Enough Arguments\n", av[0]);
		printf("%s: num_philos time_to_die time_to_eat"
			" time_to_sleep number_of_times_each_philo_must_eat"
			"(optional)\n", av[0]);
	}
	else if (ac > 6 && flag == 0)
		printf("%s: Too many arguments\n", av[0]);
	else if (flag == 1)
	{
		printf("%s: Invalid arguments\n", av[0]);
	}
}
