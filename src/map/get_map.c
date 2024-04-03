/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:30:00 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 17:41:06 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	**get_map(char **buf)
{
	int		i;
	char	**ret;

	i = 1;
	ret = (char **)malloc(sizeof(char *) * (ft_tablen(buf)));
	while (buf[i])
	{
		ret[i - 1] = ft_strdup(buf[i]);
		i++;
	}
	return (ret);
}
