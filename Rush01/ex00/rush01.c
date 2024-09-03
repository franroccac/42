#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	n;
	int	i;
	char	*datosup;
	char	*datosdown;
	char	*datosleft;
	char	*datosright;
	char	size;

	n = 4;
	size = n - 1 + '0';
	datosup = "4321";
	datosdown = "1222";
	datosleft = "4321";
	datosright = "1222";
	int **array = malloc(sizeof(int *) * n);

	i = 0;
	while (i < n)
	{
		array[i] = malloc(sizeof(int) * n);
		i++;
	}
	int fil;
	int col;
	int cont;

	fil = 0;
	while (fil < n)
	{
		col = 0;
		while (col < n)
		{
			cont = 0;
			while (cont < n)
			{
				if (datosup[cont] == n + '0')
				{
					array[0][0] = 1;
					array[1][0] = 2;
					array[2][0] = 3;
					array[3][0] = 4;
				}
				if (datosdown[cont] == n + '0')
				{
					array[0][0] = 4;
					array[1][0] = 3;
					array[2][0] = 2;
					array[3][0] = 1;
				}
				if (datosleft[cont] == n + '0')
				{
					array[0][0] = 1;
					array[0][1] = 2;
					array[0][2] = 3;
					array[0][3] = 4;
				}
				if (datosright[cont] == n + '0')
				{
					array[0][0] = 4;
					array[0][1] = 3;
					array[0][2] = 2;
					array[0][3] = 1;
				}
				else if (datosup[cont] == size)
					array[2][cont] = n;
				else if (datosdown[cont] == size)
					array[1][cont] = n;
				else if (datosleft[cont] == size)
					array[cont][2] = n;
				else if (datosright[cont] == size)
					array[cont][1] = n;
				cont++;
			}
			printf("%d", array[fil][col]);
			col++;
		}
		fil++;
		write(1, "\n", 1);
	}
	return (0);
}