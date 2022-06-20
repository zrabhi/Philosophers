#include "philosophers.h"

bool    ft_create_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {
        if (pthread_create(&head->thr, NULL, philo_routine, &head->id) == -1)
                return(false);
        head = head->next;   
    }
    return(true);
}
void    philo_routine()
{

    printf("im workin on it\n");
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

bool ft_init_mutex(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(head)
    {
        if(pthread_mutex_init((&head->fork), NULL) == -1)
            return (false);
        head = head->next;
    }
    return(true);
}

bool ft_mutex_destroy(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(head)
    {
        if(pthread_mutex_destroy(&head->fork) == -1 )
            return (false);
        head = head->next;
    }
    return(false);
}
