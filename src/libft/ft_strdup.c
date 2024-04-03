/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:41:30 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 14:47:06 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	*ft_strdup(char *src)
{
	char			*str;
	unsigned int	i;

	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	if (str == 0)
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
