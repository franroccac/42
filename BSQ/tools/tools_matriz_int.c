/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvera <bvera@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:46:57 by bvera             #+#    #+#             */
/*   Updated: 2024/08/26 23:46:59 by bvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_char2(char valor)
{
	write(1, &valor, 1);
}

void	ft_print_matrix(int **matrix, int rows, int columns)
{
	int	start_row;
	int	start_column;

	start_row = 0;
	while (start_row < rows)
	{
		start_column = 0;
		while (start_column < columns)
		{
			if (start_column == columns - 1)
			{
				print_char2(matrix[start_row][start_column] + '0');
			}
			else
			{
				print_char2(matrix[start_row][start_column] + '0');
				write(1, " ", 1);
			}
			start_column++;
		}
		write(1, "\n", 1);
		start_row++;
	}
}

int	**memory_malloc_matrix(int rows, int columns)
{
	int	**matrix;
	int	aux_row;
	int	aux_row_malloc;

	matrix = malloc(rows * sizeof(int *));
	if (!matrix)
		return (NULL);
	aux_row = 0;
	aux_row_malloc = 0;
	while (aux_row < rows)
	{
		matrix[aux_row] = malloc(columns * sizeof(int *));
		if (matrix[aux_row] == NULL)
		{
			while (aux_row_malloc < aux_row)
			{
				free(matrix[aux_row_malloc]);
				aux_row_malloc++;
			}
			free(matrix);
			return (NULL);
		}
		aux_row++;
	}
	return (matrix);
}

void	memory_free_matrix(int **matrix, int rows)
{
	int	aux_row;

	aux_row = 0;
	while (aux_row < rows)
	{
		free(matrix[aux_row]);
	}
	free(matrix);
}
/*char 	**get_matriz()
{
	int	*a;
	int	*b;

	a = malloc(4 * sizeof(int));
	b = malloc(4 * sizeof(*a));

	//Preguntar a illiac como trabajar esto con  [][]
	return ;
}*/

void	ft_load_matrix(int **matrix)
{
	matrix[0][0] = 0;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 0;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 0;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 0;
}
//Lectura de Matriz
int	main(void)
{	
	int	**matrix;

	matrix = memory_malloc_matrix(4,4);
	write(1, "por qu\n", 7);
	ft_load_matrix(matrix);
	write(1, "por qu\n", 7);
	ft_print_matrix(matrix, 4, 4);
	write(1, "por qu\n", 7);
	memory_free_matrix(matrix,4);
	write(1, "por qu\n", 7);
	return (0);
}