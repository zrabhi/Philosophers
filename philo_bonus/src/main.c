/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:53:53 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 01:59:06 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_init_semaphore(t_table *table)
{
	sem_unlink("semaphore");
	table->fork = sem_open("semaphore", O_CREAT, 0777, \
		table->number_of_philosophers);
	if (!table->fork)
		return (0);
	sem_unlink("printer");
	table->printer = sem_open("printer", O_CREAT, 0777, table->print);
	if (!table->printer)
		return (0);
	return (1);
}

int	ft_init_child_process(t_table *table, int *pid)
{
	int	i;

	i = 0;
	while (i++ < table->number_of_philosophers)
	{
		pid[i] = fork();
		table->philo_age = ft_get_time();
		if (pid[i] == 0)
		{
			table->last_meal = ft_get_time();
			table->id = i;
			pthread_create(&(table->thr), NULL, ft_philosopher_routine, \
					(void *)table);
			pthread_detach(table->thr);
			if (!ft_death(table))
				exit(EXIT_FAILURE);
		}
	}
	wait_pid(pid, table);
	return (1);
}

int	main(int ac, char **av)
{
	t_table		*table;
	int			*pid;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (0);
	else if (!ft_init(ac, av, table) || !ft_check(av, ac))
		return (0);
	pid = malloc(sizeof(int) * table->number_of_philosophers);
	if (!pid)
		return (0);
	else if (!ft_init_semaphore(table) || !ft_init_child_process(table, pid))
		return (0);
}
