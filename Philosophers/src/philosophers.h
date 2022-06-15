#ifndef     PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_philo{

    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    pthread_t *thr;
}   t_philo;


typedef struct s_data{
    long age;
    t_philo *philo;
    pthread_mutex_t *fork;
} t_data;

int	ft_atoi(const char *str);
long long ft_get_time(void);

#endif







