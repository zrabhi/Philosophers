#include "philosophers.h"

long long ft_get_time(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return((time.tv_sec + 1) / 1000LL);
}

// void    ft_philo_routine(void)
// {
//     printf("thread created succesfully , still need to work on philo routine");

// }

// void    ft_creat_threads(t_philo *philo, int number_of_philo)
// {
//     int i;

//     i = -1;
//     while(++i)
//         pthread_create(philo->thr,)


// }