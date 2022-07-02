/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:31 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 18:19:14 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_eating(t_data *head)
{
    long long time;
    time = ft_get_time() - head->philo_age;
    
    red();
    sem_wait(head->table->printer);
    printf("%lld  %d is eating\n", time, head->id);
    sem_post(head->table->printer);
    
}

void    ft_thinking(t_data *head)
{
    long long time;
    
    red();
    sem_wait(head->table->printer);
    time  = ft_get_time() - head->philo_age;
    printf("%lld  %d is thinking\n", time, head->id);
    sem_post(head->table->printer);
}

void    ft_is_sleeping(t_data *head)
{
    long long time;
    
    red();
    sem_wait(head->table->printer);
    time = ft_get_time() - head->philo_age;
    printf("%lld  %d is sleeping\n", time, head->id);
    sem_post(head->table->printer);
}

void    ft_has_taken_fork(t_data *head)
{
    long long time;

    red();
    sem_wait(head->table->printer);
    time = ft_get_time() - head->philo_age;
    printf("%lld  %d has taken fork\n", time, head->id);
    sem_post(head->table->printer);
}