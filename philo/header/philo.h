/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/24 18:13:49 by mtoof            ###   ########.fr       */
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
	unsigned long	time_to_die;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				meal_num;
	int				death;
	int				finish;
	t_philo			*philo;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	eaten;
	pthread_mutex_t	lock;
}					t_data;

long				ft_atol(const char *str);
int					check_args(int ac, char **av);
int					data_init(t_data *data, char **av, int ac);
int					init_mutex(t_data *data);
void				ft_usleep(long time);
unsigned long		get_time(void);
void				print_msg(unsigned long time, t_philo *philo, char *msg);
unsigned long		realtime(unsigned long time);
void				*routine(void *data);
void				eaten_died_check(pthread_t *tr, t_data *data);
void				join_destroy(pthread_t	*tr, t_data data);

#endif