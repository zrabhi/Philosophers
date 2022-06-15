#include "philosophers.h"
void    ft_init(int ac,char **av, t_philo *philo)
{
    if(ac >= 5)
    {
        philo->number_of_philosophers = ft_atoi(av[1]);
        philo->time_to_die = ft_atoi(av[2]);
        philo->time_to_eat = ft_atoi(av[3]);
        philo->time_to_sleep = ft_atoi(av[4]);
    }
    else if (ac == 6 )
        philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else 
        return ;
}

static void    ft_philo_routine()
{
    long long time = ft_get_time();
    printf("%lld   thread created succesfully , still need to work on philo routine\n", time);


}

int main(int ac, char **av)
{
    int i;
    int j;
    t_philo *philo;
    philo = malloc(sizeof(t_philo));
    if(!philo)
        return(0);
    ft_init(ac, av, philo);
    i = 0;
    j = 0;
    if(ac == 6)
    {
        philo->number_of_philosophers = ft_atoi(av[1]);
        philo->time_to_die = ft_atoi(av[2]);
        philo->time_to_eat = ft_atoi(av[3]);
        philo->time_to_sleep = ft_atoi(av[4]); 
    }
    while(j++ <  philo->number_of_philosophers)
        {
            pthread_create(&philo->thr, NULL, ft_philo_routine, NULL);
            sleep(1);
        }
}