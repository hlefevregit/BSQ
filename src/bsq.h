/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:33 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 18:08:34 by hulefevr         ###   ########.fr       */
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

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_type
{
	char	empty;
	char	obstacle;
	char	fill;
	char	*nb;
}		t_type;

typedef struct s_game
{
	char	**map;
	char	**cpy;
	char	*info;
	t_type	type;
	t_pos	**obstacle;
}		t_game;

t_game	check_errors(t_game game);
t_game	get_obstacle_pos(t_game game);
t_game	game_check_fullempty(t_game game);

char	**ft_split(char *s, char c);
char	**get_map(char **buf);

char	*ft_strdup(char *src);

int		ft_strlen(char *str);
int		ft_tablen(char **tab);
int		ft_atoi(char *str);
int		ft_strerror(char *str);
int		ft_obstacle_nb(t_game game);

void	ft_putstr_fd(char *str, int fd);
void	print_map(t_game game);
void	ft_putchar_fd(char c, int fd);

#endif