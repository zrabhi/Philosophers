/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:31 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 13:30:32 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_eating(t_data *head)
{
    long long time;
    time = ft_get_time() - head->philo_age;
    
    red();
    pthread_mutex_lock(&(head->table->data));
    printf("%lld  %d is eating\n", time, head->id);
    pthread_mutex_unlock(&(head->table->data));
}

void    ft_thinking(t_data *head)
{
    long long time;
    
    red();
    pthread_mutex_lock(&(head->table->data));
    time  = ft_get_time() - head->philo_age;
    printf("%lld  %d is thinking\n", time, head->id);
    pthread_mutex_unlock(&(head->table->data));
}

void    ft_is_sleeping(t_data *head)
{
    long long time;
    
    red();
    pthread_mutex_lock(&(head->table->data));
    time = ft_get_time() - head->philo_age;
    printf("%lld  %d is sleeping\n", time, head->id);
    pthread_mutex_unlock(&(head->table->data));
}

void    ft_has_taken_fork(t_data *head)
{
    long long time;

    red();
    pthread_mutex_lock(&(head->table->data));
    time = ft_get_time() - head->philo_age;
    printf("%lld  %d has taken fork\n", time, head->id);
    pthread_mutex_unlock(&(head->table->data));
}