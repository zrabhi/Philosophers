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

#include "philosophers.h"

int main(int ac, char **av)
{
    printf("im here");
    t_table *table;
    t_data *head;
    int     pid;
    int     i;

    // pid = 0;
    table = malloc(sizeof(t_table));
    if(!table)
        return (0);
    if (!ft_init(ac, av, table))
        return (0);
    if (!ft_check(av, ac))
        return (0);
    ft_get_philo_data(table);
    sem_unlink("semaphore");
    table->fork = sem_open("semaphore", O_CREAT, 0777, table->number_of_philosophers);
    if(!table->fork)
        return (0);
    sem_unlink("printer"); 
    table->printer = sem_open("printer", O_CREAT, 0777, table->print);
    if(!table->printer)
        return(0);
    head = table->head;
    i = 0;
    while (++i < table->number_of_philosophers)
    {
        pid = fork();
        if (pid == 0)
        {
            head->last_meal = ft_get_time();
            pthread_create(&(head->thr), NULL, ft_philosopher_routine, (void *)head);
            pthread_detach(head->thr);
        }
            head = head->next;
    }
    // if (!ft_death(table->head, table))
    //     return(0);
    // if (!ft_num_of_time_to_eat(table))
    //     return(0);
}