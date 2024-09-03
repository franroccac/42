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

void	ft_putstr(char *str);
void	ft_putint(int num);

void	print_char(char valor)
{
	write(1, &valor, 1);
}

void	ft_print_matrix_str(char **matrix, int rows, int columns)
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
				print_char(matrix[start_row][start_column]);
			}
			else
			{
				print_char(matrix[start_row][start_column]);
				write(1, " ", 1);
			}
			start_column++;
		}
		write(1, "\n", 1);
		start_row++;
	}
}

char	**memory_malloc_matrix_str(int rows, int columns)
{
	char	**matrix;
	int	aux_row;
	int	aux_row_malloc;

	matrix = malloc(rows * sizeof(char *));
	if (!matrix)
		return (NULL);
	aux_row = 0;
	aux_row_malloc = 0;
	while (aux_row < rows)
	{
		matrix[aux_row] = malloc(columns * sizeof(char *));
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

void	memory_free_matrix_str(char **matrix, int rows)
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

void    ft_load_matrix_str_row(char **matrix, int pos, int columns, char *str)
{
        int     i;

        i = 0;
        while (i <=  columns)
        {
                matrix[pos][i] = str[i];
                i++;
        }
}

void	ft_load_matrix_str(char *file, char **matrix, int columns)
{
	int	pos;
	int	i;
        int     size;
        char    *str;

	pos = 0;
	i = 0;
        size = 0;
        str = malloc(columns + 1);
	while (file[i])
	{
		if ((file[i] == '\n') || ((file[i + 1]) == '\0'))
                {
                        pos++;		        
                        if (pos >= 2)
                        {
                                if (file[i + 1] == '\0')
		                {
                                        str[size] = file[i];                                             	
                                        str[size + 1] = '\0';                                                  
                                        ft_load_matrix_str_row(matrix, (pos - 2), (size + 1), str);	
		                }
		                else
                                        ft_load_matrix_str_row(matrix, (pos - 2), size, str);
                        }
                        size = -1;
                }else if (pos >= 1)
                               str[size] = file[i]; 
		i++;
                size++;
	}
}
//Lectura de Matriz
/*int	main(void)
{	
	char	**matrix;

	matrix = memory_malloc_matrix_str(4, 4);
	write(1, "por qu\n", 7);
	//ft_load_matrix_str(matrix);
	write(1, "por qu\n", 7);
	ft_print_matrix_str(matrix, 4, 4);
	write(1, "por qu\n", 7);
	memory_free_matrix_str(matrix,4);
	write(1, "por qu\n", 7);
	return (0);
}*/