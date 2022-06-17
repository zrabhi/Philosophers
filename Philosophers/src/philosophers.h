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


typedef struct s_philo{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    pthread_t thr;
}   t_philo;

typedef struct s_list{
    int id;
    int index;
    int is_dead;
    int right_fork;
    int left_fork;
    struct s_list *next;
    struct s_list *previous;
} t_list;


typedef struct s_data{
    struct s_list  *tail;
    struct s_list  *head;
} t_data;


void    ft_crearlst(t_data **data, t_list *lst);
t_data     *ft_addnode(t_data *data, int id);
// t_data *ft_addnode(int id);
int         ft_atoi(const char *str);
long long   ft_get_time(void);
int         ft_isdigit(int c);
void ft_get_lst(int philo_number, t_data *data);
t_list *ft_newnode(int id);
#endif







