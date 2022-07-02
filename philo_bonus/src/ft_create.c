/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:29:56 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 13:29:57 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool ft_join_threads(t_table *table)
{
    t_data *head;
    int i;

    i = -1;
    head = table->head;
    while(++i < table->number_of_philosophers)
    {
          if(pthread_join(head->thr, NULL))
            return(false);
        head = head->next; 
    }
    return(false);
}

