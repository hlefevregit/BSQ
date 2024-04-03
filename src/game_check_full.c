/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:40:04 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 17:46:28 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_obstacle_nb(t_game game)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == game.type.obstacle)
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

t_game	game_check_fullempty(t_game game)
{
	int	i;
	int	j;

	if (ft_obstacle_nb(game) == 0)
	{
		i = 0;
		while (game.cpy[i])
		{
			j = 0;
			while (game.cpy[i][j])
			{
				game.cpy[i][j] = game.type.fill;
				j++;
			}
		}
		i++;
	}
	return (game);
}