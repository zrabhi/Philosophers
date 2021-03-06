/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:50:32 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 01:53:35 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_usleep(long long time)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
}

long	ft_new_time(t_table *table)
{
	return (ft_get_time() - table->philo_age);
}

void	kill_pids(int *pid, t_table *table)
{
	int	i;

	i = 0;
	while (i++ < table->number_of_philosophers)
		kill(pid[i], SIGINT);
}

void	wait_pid(int *pid, t_table *table)
{
	int	status;
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_FAILURE)
			{
				kill_pids(pid, table);
				break ;
			}
		}
	}
}
