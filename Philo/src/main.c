/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:18 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 13:30:19 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

int main(int ac, char **av)
{
    t_table *table;
    t_data *head;
    int     i;

    table = malloc(sizeof(t_table));
    if(!table)
        return (0);
    if (!ft_init(ac, av, table))
     {
    //     ft_free_all(&table);
        return (0);
    }
    if (!ft_check(av, ac))
    {
        // ft_free_all(&table);
        return (0);
    }
    ft_get_philo_data(table);
    pthread_mutex_init(&(table->data), NULL);
    table->fork = ft_init_mutex(&table);
    head = table->head;
    i = -1;
    while(++i < table->number_of_philosophers)
    {
        head->last_meal = ft_get_time();
        // usleep(100);
        pthread_create(&(head->thr), NULL, ft_philosopher_routine, (void *)head);
        pthread_detach(head->thr);
        head = head->next;
    }
    if(!ft_death(table->head, table))
        return(0);
    if(ft_num_of_time_to_eat(table))
        return(0);
}