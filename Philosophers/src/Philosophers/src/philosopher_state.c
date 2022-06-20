#include "philosophers.h"

void    ft_eating(t_data *head)
{
    long long time;

    time = ft_get_time() - head->philo_age;
    pthread_mutex_lock(&(head->data));
    printf("%lld philosopher %d is eating\n", time, head->id);
    pthread_mutex_unlock(&(head->data));
}

void    ft_thinking(t_data *head)
{
    long long time;

    pthread_mutex_lock(&(head->data));
    time  = ft_get_time() - head->philo_age;
    printf("%lld philosopher %d is thinking\n", time, head->id);
    pthread_mutex_unlock(&(head->data));
}

void    ft_is_sleeping(t_data *head)
{
    long long time;

    pthread_mutex_lock(&(head->data));
    time = ft_get_time() - head->philo_age;
    printf("%lld philosopher %d is sleeping\n", time, head->id);
    pthread_mutex_unlock(&(head->data));
}

void    ft_has_taken_fork(t_data *head)
{
    long long time;

    pthread_mutex_lock(&(head->data));
    time = ft_get_time() - head->philo_age;
    printf("%lld philosopher %d had taken fork\n", time, head->id);
    pthread_mutex_unlock(&(head->data));
}