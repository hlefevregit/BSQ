/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:24:15 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 18:43:28 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	draw_square(t_game game, int pos_x, int pos_y, int size)
{
	int	x;
	int	y;

	x = pos_x;
	while (x < pos_x + size)
	{
		y = pos_y;
		while (y < pos_y + size)
		{
			if (game.cpy[y][x] == game.type.obstacle)
				return (0);
			game.cpy[y][x] = game.type.fill;
			y++;
		}
		x++;
	}
	return (1);
}

int	test_square(t_game game, int pos_x, int pos_y, int size)
{
	int	x;
	int	y;

	x = pos_x;
	while (x < pos_x + size)
	{
		y = pos_y;
		while (y < pos_y + size)
		{
			if (game.cpy[y][x] == game.type.obstacle)
				return (0);
			y++;
		}
		x++;
	}
	
	return (1);
}

t_game	draw_squares_scan(t_game game)
{
	int	sizesquare;
	int pos_x;
	int	pos_y;

	sizesquare = ft_atoi(game.type.nb);
	
	while (sizesquare > 0)
	{
		pos_x = 0;
		while (pos_x <= ft_strlen(game.cpy[0]) - sizesquare)
		{
			pos_y = 0;
			while (pos_y <= ft_atoi(game.type.nb) - sizesquare)
			{
				if (test_square(game, pos_x, pos_y, sizesquare) == 1)
					return (game);
				pos_y++;
			}
			pos_x++;
		}
		sizesquare--;
	}
	return (game);
}
