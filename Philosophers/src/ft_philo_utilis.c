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


void	ft_usleep(int time)
{
    long long start;

    start = ft_get_time();
    usleep((time * 0.9) * 1000);
    while(ft_get_time() - start < time)
    {
        usleep(10);
    }
}