#include <stdio.h>
#include <string.h>

#define size_y 5

void	draw_square(char tab[size_y][size_y + 1], int pos_x, int pos_y,
		int size)
{
	int	x;
	int	y;

	x = pos_x;
	while (x < pos_x + size)
	{
		y = pos_y;
		while (y < pos_y + size)
		{
			if (tab[y][x] == 'o')
			{
				return ;
			}
			tab[y][x] = 'x';
			y++;
		}
		x++;
	}
}

void	draw_squaresAvecBalayage(char tab[size_y][size_y + 1], int sizeInitiale)
{
	int	sizesquare;

	sizesquare = sizeInitiale;
	int pos_x, pos_y;
	while (sizesquare > 0)
	{
		pos_x = 0;
		while (pos_x <= size_y - sizesquare)
		{
			pos_y = 0;
			while (pos_y <= size_y - sizesquare)
			{
				init_tab(tab);
				draw_square(tab, pos_x, pos_y, sizesquare);
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
	char	tab[size_y][size_y + 1];

	draw_squaresAvecBalayage(tab, size_y - 1);
	return (0);
}
