#include "philosophers.h"

bool ft_join_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {
          if(pthread_join(head->thr, NULL))
            return(false);
        head = head->next; 
    }
    return(false);
}

pthread_mutex_t *ft_init_mutex(t_table **table)
{
    int i;
    pthread_mutex_t *fork;

    fork = malloc(sizeof(pthread_mutex_t) * (*table)->number_of_philosophers);
    i = -1;
    while(++i < (*table)->number_of_philosophers)
    {
        if (pthread_mutex_init(&(fork[i]), NULL))
            return (NULL);
    }
    return(fork);
}



bool ft_mutex_destroy(t_table *table)
{
    int i;

    i = -1;
    while(i < table->number_of_philosophers)
    {
        if(pthread_mutex_destroy(&(table->fork[i++])))
            return (false);
    }
    return(false);
}
