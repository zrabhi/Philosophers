/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:08:07 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 02:12:58 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_eating(t_table *table)
{
	red();
	sem_wait(table->printer);
	printf("%lld  %d is eating\n", \
		ft_get_time() - table->philo_age, table->id);
	sem_post(table->printer);
}

void	ft_thinking(t_table *table)
{
	red();
	sem_wait(table->printer);
	printf("%lld  %d is thinking\n", \
		ft_get_time() - table->philo_age, table->id);
	sem_post(table->printer);
}

void	ft_is_sleeping(t_table *table)
{
	red();
	sem_wait(table->printer);
	printf("%lld  %d is sleeping\n", \
		ft_get_time() - table->philo_age, table->id);
	sem_post(table->printer);
}

void	ft_has_taken_fork(t_table *table)
{
	red();
	sem_wait(table->printer);
	printf("%lld  %d has taken fork\n", \
		ft_get_time() - table->philo_age, table->id);
	sem_post(table->printer);
}
