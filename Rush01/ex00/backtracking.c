#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	**array()
{
	int	i;
	int	n;
	int	**array;

	i = 0;
	n = 4;
	**array = malloc(sizeof(int *) * n);
	while (i < n)
	{
		array[i] = malloc(sizeof(int) * n);
		i++;
	}
	return (array);
}

int posiciones (int **array, int col, int fil, int num)
{
	int	i;

	i = 0;
	fil = 0;
	col = 0;
	while (fil < 4)
	{
		while (i < 4)
		{
			if (array[fil][i] == num)
				return (0);
			i++;
		}
		fil++;
	}
	while (col < 4)
	{
		while (i < 4)
		{
			if (array[i][col] == num)
				return (0);
			i++;
		}
		col++;
	}
	return (1);
}

void backtracking()
{
	int	fil;
	int	col;
	int	n;

	fil = 0;
	while (fil < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (array[fil][col] == 0)
			{
				n = 1;
				while (n == 4)
				{
					if (posiciones(fil, col, n))
					{
						array[fil][col] = n;
						backtracking();
						array[fil][col] = 0;
					}
					return (0);
				}
				n++;
			}
		}
	}
}