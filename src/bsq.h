/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:33 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 12:54:16 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game
{
	int		error;
	char 	**map;
	char	*info;
}		t_game;

char	**ft_split(const char *s, char c);

char	*ft_strdup(char *src);

int		ft_strlen(char *str);
int		ft_tablen(char **tab);

#endif