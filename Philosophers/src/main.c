#include "philosophers.h"

// static void     ft_lstprintf(t_table *table)
// {
//     t_data *head;
//     int     i;

//     head = table->head;
//     i = -1;    
//     while(++i < table->number_of_philosophers)
//     {
//         printf("philosopher number : %5d\n", head->id);
//         head = head->next;
//     }
//     printf("\n");
// }


int main(int ac, char **av)
{
    t_table *table;

    table = malloc(sizeof(t_table));
    if(!table)
        return (0);
    if (!ft_init(ac, av, table))
        return (0);
    if (!ft_check(av, ac))
        return (0);
    ft_get_philo_data(table);
    // pthread_mutex_init(&(table->head->data), NULL);
    table->fork = ft_init_mutex(table);
    if(!ft_create_threads(table))
        return (0);
    if(!ft_join_threads(table))
        return (0);
}