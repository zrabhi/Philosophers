#include "philosophers.h"

long long ft_get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000LL);
}

void    *ft_philosopher_routine(void * param)
{
    t_data *philo;
    int i;

    philo = (t_data *) param;
    i = philo->id;
    while(1)
    {
        if(i == ft_lstsize(philo))
            break;
        ft_thinking(philo);
        pthread_mutex_lock(&(philo->table->fork[i]));
        ft_has_taken_fork(philo);
        pthread_mutex_lock(&(philo->table->fork[(i + 1) % philo->table->number_of_philosophers]));
        ft_has_taken_fork(philo);
        ft_eating(philo);
        ft_usleep(philo->table->time_to_eat);
        pthread_mutex_unlock(&(philo->table->fork[i]));
        pthread_mutex_unlock(&(philo->table->fork[(i + 1) % philo->table->number_of_philosophers]));
        ft_is_sleeping(philo);
        ft_usleep(philo->table->time_to_sleep);
        philo = philo->next;
    } 
    return (0);
}

