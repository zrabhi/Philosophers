#include "philosophers.h"

int ft_lstsize(t_data *data)
{
    int i;

    i = 0;
    while (i < data->table->number_of_philosophers && data)    
    {
        i++;
        data = data->next;
    }
    return (i);
}

bool ft_num_of_time_to_eat(t_table *table)
{
    int i;

    i = -1;
    while(++i < table->number_of_philosophers)
    {
        if(i == table->number_of_times_each_philosopher_must_eat)
            return (true);
    }
    return(false);
}


void	ft_usleep(long long time)
{
    long long start;

    start = ft_get_time();
    usleep((time * 0.9) * 1000);
    while(ft_get_time() - start < time)
    {
        usleep(50);
    }
}

long ft_new_time(t_table *table)
{
    return (ft_get_time() - table->head->philo_age);
}