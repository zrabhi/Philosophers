/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:18:41 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/16 22:24:36 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

t_data	*ft_newnode(int id)
{
	t_data	*philo_data;

	philo_data = malloc(sizeof(t_data));
	if (!philo_data)
		return (NULL);
	philo_data->next = NULL;
	philo_data->previous = NULL;
	philo_data->id = id;
	philo_data->is_dead = 0;
	philo_data->fork_num = 0;
	philo_data->t_eat = 0;
	philo_data->philo_age = ft_get_time();
	return (philo_data);
}

t_table	*ft_creatphilo_data(t_table **table, t_data *data)
{
	t_data	*tmp;

	tmp = NULL;
	if (!data)
		return (NULL);
	if (!(*table)->head)
	{
		(*table)->head = data;
		(*table)->head->next = NULL;
		(*table)->head->previous = (*table)->head;
		(*table)->head->table = (*table);
	}
	else
	{
		tmp = (*table)->head->previous;
		(*table)->head->previous = data;
		data->next = (*table)->head;
		data->previous = tmp;
		tmp->next = data;
		data->table = (*table);
	}
	return (*table);
}

void	ft_get_philo_data(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philosophers)
		table = ft_creatphilo_data(&table, ft_newnode(i + 1));
}

/*void	ft_free_all(t_table **table)
{
	t_data	*tmp;

	if (table && *table)
	{
		if ((*table)->head)
		{
			tmp = (*table)->head;
			while (tmp)
			{
				(*table)->head = (*table)->head->next;
				free(tmp);
				tmp = (*table)->head;
			}
			(*table)->head = NULL;
			free((*table)->head);
		}
		free(*table);
	}
}*/
