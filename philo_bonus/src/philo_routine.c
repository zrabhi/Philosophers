/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:59:21 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 02:36:02 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	ft_death(t_table *table)
{
	int	i;

	while (true)
	{
		i = -1;
		while (++i < table->number_of_philosophers)
		{
			if (ft_get_time() - table->last_meal > table->time_to_die)
			{
				sem_wait(table->printer);
				printf("%lld  %d died\n", \
					(ft_get_time() - table->philo_age), table->id);
				return (false);
			}
			if (table->t_eat == \
					table->number_of_times_each_philosopher_must_eat * \
						table->number_of_philosophers)
				return (false);
		}
		usleep(50);
	}
	return (true);
}

void	*ft_philosopher_routine(void *param)
{
	t_table	*table;

	table = (t_table *) param;
	if ((table->id - 1) % 2 == 0)
		usleep(600);
	while (true)
	{
		sem_wait(table->fork);
		ft_has_taken_fork(table);
		sem_wait(table->fork);
		ft_has_taken_fork(table);
		table->last_meal = ft_get_time();
		ft_eating(table);
		ft_usleep(table->time_to_eat);
		table->t_eat++;
		sem_post(table->fork);
		sem_post(table->fork);
		ft_is_sleeping(table);
		ft_usleep(table->time_to_sleep);
		ft_thinking(table);
	}
	return (false);
}
