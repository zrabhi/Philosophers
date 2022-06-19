#include "philosophers.h"

bool    ft_create_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {

       if (pthread_create(&(head->thr), NULL, ft_philosopher_routine, (void *) head))
          {  
                return(false);
          }
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
          if(pthread_join(&(head->thr), NULL))
            return(false);
        head = head->next; 
    }
    return(false);
}

// pthread_mutex_t *ft_init_mutex(pthread_mutex_t *fork, t_table *table)
// {
//     int i;

//     i = 0;
//     while(i++ < table->number_of_philosophers)
//     {
//         if(pthread_mutex_init(&(table->head->fork[i]), NULL))
//             return (NULL);
//     }
//     return(table->head->fork);
// }

bool	init_mutexes(t_table **table)
{
	int				i;

	i = 0;
	(*table)->fork = malloc(sizeof(pthread_mutex_t) * (*table)->number_of_philosophers);
	while (i++ < (*table)->number_of_philosophers)
	{
		if (pthread_mutex_init(&((*table)->fork[i]), NULL))
			return (false);
        printf("this is for %d\n", i);
	}
	return ((table));
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
