/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:20 by zakaria           #+#    #+#             */
/*   Updated: 2022/07/17 02:26:08 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

static void	ft_init_args(char **av, t_table *table)
{
		table->number_of_philosophers = ft_atoi(av[1]);
		table->time_to_die = ft_atoi(av[2]);
		table->time_to_eat = ft_atoi(av[3]);
		table->time_to_sleep = ft_atoi(av[4]);
		table->is_dead = 0;
		table->number_of_times_each_philosopher_must_eat = -1;
		table->t_eat = 0;
		table->philo_age = ft_get_time();
		table->last_meal = ft_get_time();
		table->print = 1;
		table->check = 0;
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
		ft_init_args(av, table);
		if (ac == 6)
			table->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		else if (ac > 6)
		{
			red();
			printf("\n\nTO MANY ARGUMENTS, YOU MUST ENTER 5 OR 6 \n\n");
			return (false);
		}
	}
	return (true);
}
