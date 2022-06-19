#include "philosophers.h"

long long ft_get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}



void    ft_philosopher_routine(void *param)
{
    long long time ;
    time  = ft_get_time();
    printf("%lld \n", time);

}

