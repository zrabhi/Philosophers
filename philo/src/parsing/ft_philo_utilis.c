/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:52:29 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 00:42:19 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/philosophers.h"

static void	ft_init_four(int ac)
{
	if (ac == 1)
	{
		red();
		printf("\n\n YOUR ENTERED NOTHING PLEASE ENTER YOUR ARGUMENTS\n\n");
	}
	else if (ac <= 4)
	{
		red();
		printf("\n\n ERORRE THERE MUST BE AT LEAST 5 ARGUMENTS \n\n");
	}
}

bool	ft_init(int ac, char **av, t_table *table)
{
	if (ac <= 4)
	{
		ft_init_four(ac);
		return (false);
	}
	else if (ac >= 5)
	{
		table->number_of_philosophers = ft_atoi(av[1]);
		table->time_to_die = ft_atoi(av[2]);
		table->time_to_eat = ft_atoi(av[3]);
		table->time_to_sleep = ft_atoi(av[4]);
		table->number_of_times_each_philosopher_must_eat = -1;
		if (ac > 5)
		{
			if (ac == 6)
				table->number_of_times_each_philosopher_must_eat = \
					ft_atoi(av[5]);
			else
			{
				printf("\n\n TO MANY ARGUMENTS,YOU MUST ENTER 5 OR 6 \n\n");
				return (false);
			}
		}
	}
	return (true);
}
