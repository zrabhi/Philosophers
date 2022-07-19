/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:43:06 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/16 22:46:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

void	ft_eating(t_data *head)
{
	long long	time;

	red();
	time = ft_get_time() - head->philo_age;
	pthread_mutex_lock(&(head->table->data));
	printf("%lld  %d is eating\n", time, head->id);
	pthread_mutex_unlock(&(head->table->data));
}

void	ft_thinking(t_data *head)
{
	long long	time;

	red();
	time = ft_get_time() - head->philo_age;
	pthread_mutex_lock(&(head->table->data));
	printf("%lld  %d is thinking\n", time, head->id);
	pthread_mutex_unlock(&(head->table->data));
}

void	ft_is_sleeping(t_data *head)
{
	long long	time;

	red();
	time = ft_get_time() - head->philo_age;
	pthread_mutex_lock(&(head->table->data));
	printf("%lld  %d is sleeping\n", time, head->id);
	pthread_mutex_unlock(&(head->table->data));
}

void	ft_has_taken_fork(t_data *head)
{
	long long	time;

	time = ft_get_time() - head->philo_age;
	red();
	pthread_mutex_lock(&(head->table->data));
	printf("%lld  %d has taken fork\n", time, head->id);
	pthread_mutex_unlock(&(head->table->data));
}
