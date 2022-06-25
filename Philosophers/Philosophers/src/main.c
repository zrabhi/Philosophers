#include "philosophers.h"

int main(int ac, char **av)
{
    t_table *table;
    t_data *head;
    int     i;

    table = malloc(sizeof(t_table));
    if(!table)
        return (0);
    if (!ft_init(ac, av, table))
        return (0);
    if (!ft_check(av, ac))
        return (0);
    ft_get_philo_data(table);
    pthread_mutex_init(&(table->data), NULL);
    table->fork = ft_init_mutex(&table);
    head = table->head;
    i = -1;
    while(++i < table->number_of_philosophers)
    {
        head->last_meal = ft_get_time();
        pthread_create(&(head->thr), NULL, ft_philosopher_routine, (void *)head);
        pthread_detach(head->thr);
        head = head->next;
    }
    if(ft_death(table->head, table))
        return(0);
}