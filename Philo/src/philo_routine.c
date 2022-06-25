/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:28 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 18:53:25 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long ft_get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool    ft_death(t_data *philo, t_table *table)
 {
    int i;

    while (1)
    {
        i = -1;
        while (++i < table->number_of_philosophers)
        {
            if (ft_get_time() - philo->last_meal > table->time_to_die)
            {
                pthread_mutex_lock(&(table->data));
                printf("%lld philosopher %d died\n", ft_get_time() - philo->philo_age, philo->id);
                return (false);
            }
            if (ft_num_of_time_to_eat(table))
                return (false);
        }
    }
    return (true);
 }

void    *ft_philosopher_routine(void *param)
{
    t_data *philo;
    int i;

    philo = (t_data *) param;
    i = philo->id - 1;
    if(i % 2 == 0)
        usleep(600);
    while (true)
    {
        pthread_mutex_lock(&(philo->table->fork[i]));
        ft_has_taken_fork(philo);    
        pthread_mutex_lock(&(philo->table->fork[(i + 1) % philo->table->number_of_philosophers]));
        ft_has_taken_fork(philo);
        philo->last_meal = ft_get_time();
        ft_usleep(philo->table->time_to_eat);
        ft_eating(philo);
        philo->t_eat++;
        pthread_mutex_unlock(&(philo->table->fork[i]));
        pthread_mutex_unlock(&(philo->table->fork[(i + 1) % philo->table->number_of_philosophers]));
        ft_usleep(philo->table->time_to_sleep);
        ft_is_sleeping(philo);
        ft_thinking(philo);
    } 
    return (false);
}