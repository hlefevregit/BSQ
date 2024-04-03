/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:02:15 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 18:10:17 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

t_game	check_info(t_game game)
{
	int	i;
	int	j;

	i = ft_strlen(game.info) - 3;
	j = 0;
	game.type.nb = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		game.type.nb[j] = game.info[j];
		j++;
	}
	i = ft_strlen(game.info) - 3;
	game.type.empty = game.info[i];
	game.type.obstacle = game.info[i + 1];
	game.type.fill = game.info[i + 2];
	if (game.info[i] == game.info[i + 1]
		|| game.info[i] == game.info[i + 2]
		|| game.info[i + 1] == game.info[i + 2])
		ft_strerror("map error\n");
	return (game);
}

int	check_len(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (ft_strlen(map[i]) != ft_strlen(map[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_good_char(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] != game.type.empty &&
				game.map[i][j] != game.type.obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_game	check_errors(t_game game)
{
	game = check_info(game);
	if (check_len(game.map) == 0)
		ft_strerror("map error 3\n");
	if (check_good_char(game) == 0)
		ft_strerror("map error 2 \n");
	if (ft_tablen(game.map) != ft_atoi(game.type.nb))
		ft_strerror("map error 1\n");
	return (game);
}
