/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:13:16 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 02:17:16 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef     PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_table {
	int			number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	int			print;
	long long	last_meal;
	int			is_dead;
	int			t_eat;
	int			id;
	int			check;
	long long	philo_age;
	pthread_t	thr;
	sem_t		*printer;
	sem_t		*fork;
}	t_table;

int			ft_init_semaphore(t_table *table);
int			ft_init_child_process(t_table *table, int *pid);
long long	ft_get_time(void);
int			ft_atoi(const char *str);
void		ft_usleep(long long time);
void		ft_get_philo_data(t_table **table);
void		red(void);
//void		philo_routine();
void		ft_eating(t_table *head);
void		ft_thinking(t_table *head);
void		ft_has_taken_fork(t_table *head);
void		ft_is_sleeping(t_table *head);
void		*ft_philosopher_routine(void *param);
bool		ft_num_of_time_to_eat(t_table *table);
bool		ft_death(t_table *table);
bool		ft_create_threads(t_table *table);
bool		ft_init(int ac, char **av, t_table *table);
bool		ft_isdigit(char *str);
bool		ft_check(char **av, int ac);
void		kill_pids(int *pid, t_table *table);
void		wait_pid(int *pid, t_table *table);
#endif
