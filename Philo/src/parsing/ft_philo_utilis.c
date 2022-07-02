/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:20 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 18:23:53 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

bool  ft_init(int ac , char **av, t_table *table)
{
    if (ac <= 4 )
        {
            if (ac == 1)
            {
                red();
                printf("\n\n YOUR ENTERED NOTHING PLEASE ENTER YOUR ARGUMENTS\n\n");
                return(false);
            }
            else if(ac <= 4)
            {
                red();
                printf("\n\n ERORRE THERE MUST BE AT LEAST 5 ARGUMENTS \n\n");
                return(false);
            }
        }
    else if( ac == 5 )
    {  
        table->number_of_philosophers = ft_atoi(av[1]);
        table->time_to_die = ft_atoi(av[2]);
        table->time_to_eat = ft_atoi(av[3]);
        table->time_to_sleep = ft_atoi(av[4]);
    }
    if (ac > 5)
        {
            if (ac == 6)
                table->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
            else{
                red();
                printf("\n\n YOUR ENTERED TO MANY ARGUMENTS, YOU MUST ENTER 5 OR 6 \n\n");
                return(false);
            } 
        }
    return(true);
}
