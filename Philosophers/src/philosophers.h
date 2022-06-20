#ifndef     PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_data{
    int             id;
    int             index;
    int             is_dead;
    int             right_fork;
    int             left_fork;
    pthread_t       thr;
    pthread_mutex_t fork;
    struct  s_data *next;
    struct  s_data *previous;
    struct s_table        *table;
} t_data;

typedef struct s_table {
    int      number_of_philosophers;
    int      time_to_die;
    int      time_to_eat;
    int      time_to_sleep;
    int      number_of_times_each_philosopher_must_eat;
    struct s_data   *head;
}   t_table;

long long   ft_get_time(void);
t_table     *ft_creatphilo_data(t_table **table, t_data *data);
t_data      *ft_newnode(int id);
int         ft_atoi(const char *str);
void        ft_get_philo_data( t_table *table);
void        red();
void        philo_routine();
bool        ft_create_threads(t_table *table);
bool        ft_init(int ac , char **av, t_table *table);
bool        ft_isdigit(char *str);
bool        ft_check(char **av, int ac);
bool        ft_create_threads(t_table *table);
bool        ft_join_threads(t_table *table);
bool        ft_init_mutex(t_table *table);
bool        ft_mutex_destroy(t_table *table);
#endif







