/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:28:50 by zrabhi            #+#    #+#             */
/*   Updated: 2022/07/17 02:28:54 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

void	red(void)
{
	printf("\033[0;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	blue(void)
{
	printf("\033[0;34m");
}
