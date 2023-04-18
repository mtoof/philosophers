/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/18 18:23:10 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	u_int64_t		time_to_die;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_num;
	int				meal_num;
	int				death;
	int				finish;
	t_philo			*philo;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_data;

long	ft_atol(const char *str);
int		check_digit(char **av);
void	args_error(int ac, char **av, int flag);
void	data_init(t_data *data, char **av, int ac);
void	init_mutex(t_data *data);

#endif