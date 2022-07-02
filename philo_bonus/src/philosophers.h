/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:35 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 18:23:39 by zakaria          ###   ########.fr       */
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


typedef struct s_data{
    int             id;
    int             is_dead;
    long long       philo_age;
    long long       last_meal;
    int             fork_num;
    pthread_t       thr;
    int             t_eat;
    struct  s_data  *next;
    struct  s_data  *previous;
    struct s_table  *table;
} t_data;

typedef struct s_table {
    int             number_of_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             number_of_times_each_philosopher_must_eat;
    int             print;
    sem_t           *printer;
    sem_t           *fork;        
    struct s_data   *head;
}   t_table;

long long   ft_get_time();
t_table     *ft_creatphilo_data(t_table **table, t_data *data);
t_data      *ft_newnode(int id);
int         ft_lstsize(t_data *data);
int         ft_atoi(const char *str);
void	    ft_usleep(long long time);
void        ft_get_philo_data( t_table *table);
void        red();
void        philo_routine();
void        ft_eating(t_data *head);
void        ft_thinking(t_data *head);
void        ft_has_taken_fork(t_data *head);
void        ft_is_sleeping(t_data *head);
void        *ft_philosopher_routine(void *param);
bool        ft_num_of_time_to_eat(t_table *table);
bool        ft_death(t_data *philo, t_table *table);
bool        ft_create_threads(t_table *table);
bool        ft_init(int ac , char **av, t_table *table);
bool        ft_isdigit(char *str);
bool        ft_check(char **av, int ac);
bool        ft_join_threads(t_table *table);
bool        ft_mutex_destroy(t_table *table);
sem_t       *ft_init_semaphore(t_table **table);
#endif







