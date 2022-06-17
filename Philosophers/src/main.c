#include "philosophers.h"
// static void     ft_lstprintf(t_data *data)
// {

    
//     while(data)
//     {
//         printf("thi philo have id : %d\n", data->id);
//         data = data->next;
//     }
//     printf("\n");
// }


// void    ft_init(int ac,char **av, t_philo *philo)
// {
//     else if (ac == 6)
//         philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
//     else 
//         return ;
// }

static void    ft_dataroutine(void)
{
    long long time = ft_get_time();
    printf("%lld   thread created succesfully , still need to work on philo routine , ", time);
}

int main(int ac, char **av)
{
    int i;
    int j;
    t_philo *philo;
    t_data  *data; 

    philo = malloc(sizeof(t_philo));
    if(!philo)
        return(0);
    data = malloc(sizeof(t_data));
    if(!data)
        return(0);
    // philo = NULL;/
    // data->head = NULL;
    // ft_init(ac, av, philo);
        philo->number_of_philosophers = ft_atoi(av[1]);
        philo->time_to_die = ft_atoi(av[2]);
        philo->time_to_eat = ft_atoi(av[3]);
        philo->time_to_sleep = ft_atoi(av[4]);
        philo->number_of_times_each_philosopher_must_eat = 0;
    
    ft_get_lst(philo->number_of_philosophers, data);
    
    printf("\n first node %d", philo->number_of_philosophers);
    // i = 0;
    // j = 0;
    // while(j++ < philo->number_of_philosophers)
    //     {
    //         pthread_create(&philo->thr, NULL, ft_dataroutine, &i);
    //         // printf(" id : %d\n", data->thr);
    //         sleep(1);
    //     }
}