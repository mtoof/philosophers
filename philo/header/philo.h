/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/01 17:54:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	int				finish;
	long long		time_to_die;
	long long		last_meal;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				meal_num;
	int				death;
	int				eaten_enough;
	t_philo			*philo;
	pthread_t		*tr;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	eaten;
	pthread_mutex_t	lmealt;
	pthread_mutex_t	lock;
	pthread_mutex_t	finish;
}					t_data;

long				ft_atol(const char *str);
int					check_args(int ac, char **av);
int					data_init(t_data *data, char **av, int ac);
int					init_mutex(t_data *data);
void				ft_usleep(t_philo *philo, long long time);
long long			get_time(void);
void				print_msg(long long time, t_philo *philo, char *msg);
long long			realtime(long long time);
void				*routine(void *data);
void				observer(t_data *data);
int					join_destroy(t_data *data);
void				put_fork(t_philo *philo);
int					checker(t_philo *philo, int flag);
#endif