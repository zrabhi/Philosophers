#include "philosophers.h"

static void     ft_lstprintf(t_table *table)
{
    t_data *head;
    int     i;

    head = table->head;
    i = -1;    
    while(++i < table->number_of_philosophers)
    {
        printf("philosopher number : %5d\n", head->id);
        head = head->next;
    }
    printf("\n");
}


static void    ft_dataroutine(void)
{
    long long time = ft_get_time();
    printf("%lld   thread created succesfully , still need to work on table routine , ", time);
}

int main(int ac, char **av)
{
    int i;
    int j;
    t_table *table;
    t_data  *data; 

    table = malloc(sizeof(t_table));
    if(!table)
        return(0);
    if (!ft_init(ac, av, table))
        return(0);
    if (!ft_check(av, ac))
        return(0);
    ft_get_philo_data(table);
    ft_lstprintf(table);
    if(!ft_create_threads(table))
        return(0);
}