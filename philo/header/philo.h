/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/05/10 15:10:32 by mtoof            ###   ########.fr       */
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
	u_int64_t		time_to_die;
	u_int64_t		last_meal;
	u_int64_t		start_time;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				meal_num;
	int				must_exit;
	int				finished;
	t_philo			*philo;
	pthread_t		*tr;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	eaten_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	*fork;
}					t_data;

long				ft_atol(const char *str);
int					check_args(int ac, char **av);
int					data_init(t_data *data, char **av, int ac);
int					init_mutex(t_data *data);
void				ft_usleep(t_philo *philo, u_int64_t time);
u_int64_t			get_time(void);
void				print_msg(t_philo *philo, char *msg);
void				*routine(void *data);
void				observer(t_data *data);
int					join_destroy(t_data *data);
int					checker(t_philo *philo, int flag);
void				error_handling(t_data *data);

#endif