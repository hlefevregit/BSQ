/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:18 by hulefevr          #+#    #+#             */
/*   Updated: 2024/04/03 13:17:52 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**get_map(char **buf)
{
	int		i;
	char	**ret;

	i = 1;
	ret = (char **)malloc(sizeof(char *) * ft_tablen(buf));
	while (buf[i])
	{
		ret[i - 1] = ft_strdup(buf[i]);
		i++;
	}
	return (ret);
}

void	start_game(t_game game)
{
	check_errors(game);
	if (game.error == 1)
		return ;
}

void	bsq(char *map)
{
	t_game game;
	int		fd;
	int		size;
	char	*buf;
	char	**string;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n");
		return ;
	}
	size = read(fd, buf, BUFSIZ);
	string = ft_split(buf, '\n');
	game.info = string[0];
	game.map = get_map(string);
	start_bsq(game);	
}

int	main(int ac, char **av)
{
	int	i;

	while (i < ac)
	{
		bsq(av[i]);
		i++;
	}
}