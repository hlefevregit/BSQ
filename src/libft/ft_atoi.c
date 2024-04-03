/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:03:52 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 18:11:14 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int	ft_atoi(char *str)
{
	size_t	i;
	int		j;
	size_t	nombre;

	j = 1;
	i = 0;
	nombre = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nombre = nombre * 10 + (str[i] - 48);
		i++;
	}
	return (nombre * j);
}
