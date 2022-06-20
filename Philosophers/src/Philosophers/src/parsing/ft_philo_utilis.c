#include "../philosophers.h"

bool  ft_init(int ac , char **av, t_table *table)
{
     if(ac == 1)
        {
            red();
            printf("\n\n YOUR ENTERED NOTHING PLEASE ENTER YOUR ARGUMENTS\n\n");
            return(false);
        }
    table->number_of_philosophers = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        table->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    return(true);
}
