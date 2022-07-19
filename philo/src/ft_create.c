/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:24:51 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/16 22:26:17 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

pthread_mutex_t	*ft_init_mutex(t_table **table)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * (*table)->number_of_philosophers);
	i = -1;
	while (++i < (*table)->number_of_philosophers)
	{
		if (pthread_mutex_init(&(fork[i]), NULL))
			return (NULL);
	}
	return (fork);
}

// bool ft_mutex_destroy(t_table *table)
// {
//     int i;

//     i = -1;
//     while(i < table->number_of_philosophers)
//     {
//         if(pthread_mutex_destroy(&(table->fork[i++])))
//             return (false);
//     }
//     return(false);
// }
