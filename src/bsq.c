/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:18 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 16:30:41 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	start_game(t_game game)
{
	game = check_errors(game);
	print_map(game);
	//game = get_obstacle_pos(game);
	//algo_game(game);
	print_map(game);
}

void	bsq(char *map)
{
	t_game game;
	int		fd;
	int		size;
	char	*buf;
	char	**string;

	buf = malloc(sizeof(char) * (BUFSIZ + 1));
	fd = open(map, O_RDONLY);
	if (fd != -1)
	{
		size = read(fd, buf, BUFSIZ);
		if (size != -1)
		{
			string = ft_split(buf, '\n');
			game.info = string[0];
			game.map = get_map(string);
			game.cpy = get_map(string);
			start_game(game);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < ac)
	{
		bsq(av[i]);
		i++;
	}
	return (0);
}