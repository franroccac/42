/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:07:18 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/26 21:07:19 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putint(int num);
void	ft_putstr(char *str);

int	ft_verify_file(char *file);
int	ft_verify_file_char(char *file);

long long int     ft_get_length_byte(char *name_file);
char	*ft_getfile(char *name_file, int length, char *file_point);
int	ft_get_column_matrix(char *file);
int	ft_get_row_matrix(char *file);

void	ft_load_matrix_str(char *str, char **matrix,int rows);
void	ft_print_matrix_str(char **matrix, int rows, int columns);
void	memory_free_matrix_str(char **matrix, int rows);
char	**memory_malloc_matrix_str(int rows, int columns);

int     start_game(char *file)
{
        char	**matrix;
        int     columns;
        int     rows;
        
        if (!ft_verify_file(file))
                return (0);
        if (!ft_verify_file_char(file))
                return (0);
	//pasar a array char probar que funciona
        columns = ft_get_column_matrix(file);
        rows = ft_get_row_matrix(file);
        matrix = memory_malloc_matrix_str(rows, columns);
        ft_load_matrix_str(file, matrix, columns);
        ft_print_matrix_str(matrix, rows, columns);
        
       // memory_free_matrix_str(matrix, rows);

        //continuar con los otros metodos
	
        return (1);
}

int	main_game(char *name_file)
{
	char	*file;
	char	*file_aux;
        long long int   length;

        length = ft_get_length_byte(name_file);
        if (length == 0)
                return (0);
	//ft_putint(length);
	file = malloc(length + 1);
	ft_getfile(name_file, length, file);
        file_aux = file;
        if ((file == NULL) || (!start_game(file_aux)))
        {
                free(file);
                return (0);
        }
        //ft_putstr(file_aux);
	free(file);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (main_game("archivo.txt"))
        {
                ft_putstr("ok");
        }
        else
        {
                ft_putstr("Error");
        }
}