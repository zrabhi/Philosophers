/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:55:17 by zakaria           #+#    #+#             */
/*   Updated: 2022/06/25 13:55:18 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ft_isdigit(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (true);
	}
	return (false);
}
