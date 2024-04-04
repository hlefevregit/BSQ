#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	init_tab(char **tab, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][size_x] = '\0';
		i++;
	}
}

int	draw_square(char **tab, int size_x, int size_y, int pos_x, int pos_y,
		int size)
{
	int x, y;
	x = pos_x;
	while (x < pos_x + size && x < size_x)
	{
		y = pos_y;
		while (y < pos_y + size && y < size_y)
		{
			if (tab[y][x] == 'o')
			{
				return (1);
			}
			tab[y][x] = 'x';
			y++;
		}
		x++;
	}
	return (0);
}

void	print_tab(char **tab, int size_x, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	draw_squaresAvecBalayage(char **tab, int size_x, int size_y,
		int sizeInitiale)
{
	int	sizesquare;
	int	pos_x;
	int	pos_y;

	sizesquare = sizeInitiale;
	while (sizesquare > 0)
	{
		pos_x = 0;
		while (pos_x <= size_x - sizesquare)
		{
			pos_y = 0;
			while (pos_y <= size_y - sizesquare)
			{
				init_tab(tab, size_x, size_y);
				draw_square(tab, size_x, size_y, pos_x, pos_y, sizesquare);
				print_tab(tab, size_x, size_y);
				printf("\n");
				pos_y++;
			}
			pos_x++;
		}
		sizesquare--;
	}
}

int	main(void)
{
	char	**tab;
	int		i;

	int size_x, size_y;
	printf("Entrez la largeur du tableau: ");
	scanf("%d", &size_x);
	printf("Entrez la hauteur du tableau: ");
	scanf("%d", &size_y);
	tab = (char **)malloc(size_y * sizeof(char *));
	i = 0;
	while (i < size_y)
	{
		tab[i] = (char *)malloc((size_x + 1) * sizeof(char));
		i++;
	}
	draw_squaresAvecBalayage(tab, size_x, size_y, size_y);
	i = 0;
	while (i < size_y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
