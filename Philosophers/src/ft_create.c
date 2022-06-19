#include "philosophers.h"

bool    ft_create_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {

        if (pthread_create(&head->thr, NULL, ft_philosopher_routine, &head) == -1)
                return(false);
        head = head->next;   
    }
    return(true);
}

bool ft_join_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {
          if(pthread_join(&head->thr, NULL) == -1)
            return(false);
        head = head->next; 
    }
    return(false);
}

bool ft_init_mutex(pthread_mutex_t *fork, t_table *table)
{
    int i;

    i = 0;
    while(i < table->number_of_philosophers)
    {
        if(pthread_mutex_init(&fork[i++], NULL) == -1)
            return (false);
    }
    return(true);
}

bool ft_mutex_destroy(pthread_mutex_t *fork, t_table *table)
{

    int i;

    i = -1;
    while(i < table->number_of_philosophers)
    {
        if(pthread_mutex_destroy(&fork[i]) == -1 )
            return (false);
    }
    return(false);
}
