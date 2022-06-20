#include "philosophers.h"

void    ft_init_philo(t_data *p_data, t_philo *philo)
{
    int i;

    i = -1;
    while(++i < philo->number_of_philosophers)
    {
        pthread_mutex_init(&(p_data->fork), NULL);
        p_data = p_data->next;
    }

}