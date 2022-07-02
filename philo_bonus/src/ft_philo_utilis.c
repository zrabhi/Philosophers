/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:29:30 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 18:52:36 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_lstsize(t_data *data)
{
    int i;

    i = 0;
    while (i < data->table->number_of_philosophers && data)    
    {
        i++;
        data = data->next;
    }
    return (i);
}

bool ft_num_of_time_to_eat(t_table *table)
{
    int i;

    i = 0;
    if(!table->number_of_times_each_philosopher_must_eat)
        return(false);
    if(i < table->number_of_philosophers)
    {
        if (table->head->t_eat < table->number_of_times_each_philosopher_must_eat)
            return (false);
    }
    return (true);
}


void	ft_usleep(long long time)
{
    long long start;

    start = ft_get_time();
    while(ft_get_time() - start < time)
    {
        usleep(50);
    }
}

long ft_new_time(t_table *table)
{
    return (ft_get_time() - table->head->philo_age);
}