/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:33:19 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 01:14:15 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	ft_death(t_data *philo, t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->number_of_philosophers)
		{
			if (ft_get_time() - philo->last_meal > table->time_to_die)
			{
				pthread_mutex_lock(&(table->data));
				printf("%lld  %d died\n", \
						ft_get_time() - philo->philo_age, philo->id);
				return (false);
			}
			if (philo->t_eat == \
				philo->table->number_of_times_each_philosopher_must_eat)
				return (false);
		}
		usleep(50);
	}
	return (true);
}

void	*ft_philosopher_routine(void *param)
{
	t_data	*philo;
	int		right;

	philo = (t_data *) param;
	if ((philo->id - 1) % 2 == 0)
		usleep(600);
	right = ((philo->id + 1) % philo->table->number_of_philosophers);
	while (1)
	{
		pthread_mutex_lock(&(philo->table->fork[philo->id - 1]));
		ft_has_taken_fork(philo);
		pthread_mutex_lock(&(philo->table->fork[right]));
		ft_has_taken_fork(philo);
		philo->last_meal = ft_get_time();
		ft_eating(philo);
		ft_usleep(philo->table->time_to_eat);
		philo->t_eat++;
		pthread_mutex_unlock(&(philo->table->fork[philo->id - 1]));
		pthread_mutex_unlock(&(philo->table->fork[right]));
		ft_usleep(philo->table->time_to_sleep);
		ft_is_sleeping(philo);
		ft_thinking(philo);
	}
	return (false);
}
