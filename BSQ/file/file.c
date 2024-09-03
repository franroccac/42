/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvera <bvera@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:48:52 by bvera             #+#    #+#             */
/*   Updated: 2024/08/27 03:48:55 by bvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putint(int num);

int		ft_verify_file(char *file);
int		ft_verify_file_char(char *file);

void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, char *src);

int		get_rows_one(char *str, int length);

char	*ft_getfile(char *name_file, long long int length, char *file_point)
{
	int				file;
	long long int	file_size;
	char			*buffer;	

	buffer = malloc(length + 1);
	file = open(name_file, O_RDONLY);
	if (file == -1)
	{
		return (NULL);
	}
	file_size = read(file, buffer, length);
	if (file_size == -1)
	{
		close(file);
		return (NULL);
	}
	buffer[length] = '\0';
	ft_strcpy(file_point, buffer);
	free(buffer);
	close(file);
	return (file_point);
}

long long int	ft_get_length_byte(char *name_file)
{
	int				file;
	long long int	file_size;
	long long int	length;
	char			buffer[1];
	char			*dic;	

	length = 0;
	file_size = 1;
	file = open(name_file, O_RDONLY);
	if (file == -1)
		return (length);
	file_size = read(file, buffer, 1);
	while (file_size > 0)
	{
		file_size = read(file, buffer, 1);
		length++;
	}
	if (file_size == -1)
		return (0);
	close(file);
	return (length);
}

int	ft_get_column_matrix(char *file)
{
	int	pos;
	int	i;
	int	size;

	pos = 0;
	i = 0;
	size = 0;
	while (file[i])
	{
		if ((file[i] == '\n') || ((file[i]) == '\0'))
		{
			pos++;
			if (pos >= 2)
				return (size);
			size = -1;
		}
		i++;
		size++;
	}
	return (size);
}

void	ft_get_row_matrix_aux(char *str, int *size, int *rows)
{
	str[*size] = '\0';
	*rows = get_rows_one(str, *size);
	*size = -1;
}

int	ft_get_row_matrix(char *file)
{
	int		rows;
	int		i;
	int		size;
	char	*str;

	rows = 0;
	i = 0;
	size = 0;
	str = malloc(1024);
	while (file[i])
	{
		if ((file[i] == '\n') || ((file[i]) == '\0'))
		{
			ft_get_row_matrix_aux(str, &size, &rows);
			free(str);
			return (rows);
		}
		else
			str[size] = file[i];
		i++;
		size++;
	}
	free(str);
	return (rows);
}
/*int     main(void)
{
        if (main_game("../archivo.txt"))
        {
                ft_putstr("ok");
        }
        else
        {
                ft_putstr("Error");
        }
                //ft_putint(777);
        
                //ft_putint(111);
}*/
