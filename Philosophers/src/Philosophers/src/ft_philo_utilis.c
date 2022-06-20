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