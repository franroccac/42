/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvera <bvera@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:49:01 by bvera             #+#    #+#             */
/*   Updated: 2024/08/27 03:49:03 by bvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putint(int num);
void	print_char(char n);

int		is_print(char valor);
int		is_digit(char valor);
int		ft_strtoint(char *str);

int	ft_verify_file_char_aux(char *file, int pos, int *flag, char *str)
{
	if ((pos >= 1) && (*flag == 1))
		if (!((str[0] == *file) || (str[1] == *file)))
			return (0);
	if ((pos == 1) && (*flag == 0))
	{
		str[0] = *(file - 3);
		str[1] = *(file - 4);
		str[2] = '\0';
		*flag = 1;
	}
	return (1);
}

int	ft_verify_file_char(char *file)
{
	int		pos;
	int		flag;
	char	*str;

	str = malloc(3);
	pos = 0;
	flag = 0;
	while (*file)
	{
		if (*file == '\n')
			pos = pos + 1;
		else if (!ft_verify_file_char_aux(file, pos, &flag, str))
		{
			free(str);
			return (0);
		}			
		if (*(file + 1) == '\0')
			if (!ft_verify_file_char_aux(file, pos, &flag, str))
			{
				free(str);
				return (0);				
			}
		file++;
	}
	free(str);
	return (1);
}

int	ft_verify_file_rows(char *file, int rows)
{
	int	pos;	
	int	i;

	pos = 0;
	i = 0;
	while (file[i])
	{
		if ((file[i] == '\n') || ((file[i + 1]) == '\0'))
			pos++;
		i++;
	}
	if (rows != (pos - 1))
		return (0);
	return (1);
}

int	get_rows_one(char *str, int length)
{
	int		i;
	int		result;
	char	*num_str;

	i = 0;
	result = 0;
	num_str = malloc(length - 2);
	while (i < length - 3)
	{
		if (!is_digit(str[i]))
		{
			free(num_str);
			return (0);
		}
		num_str[i] = str[i];
		i++;
	}
	num_str[i] = '\0';
	result = ft_strtoint(num_str);
	free(num_str);
	return (result);
}

int	verify_row_one(char *str, int length)
{
	int	i;

	i = 0;
	if (length < 4)
		return (0);
	if (!is_print(str[length - 1]))
		return (0);
	if (!is_print(str[length - 2]))
		return (0);
	if (!is_print(str[length - 3]))
		return (0);
	if (!((str[length -1] != str[length - 2])
			&& (str[length -1] != str[length - 3])
			&& (str[length -2] != str[length - 3])))
		return (0);
	return (1);
}

int	ft_verify_row(char *file, int size, int pos, int *columns)
{
	int		i;
	int		rows;
	char	*str;

	rows = 0;
	str = malloc(size + 1);
	file = file - size;
	i = 0;
	while (i < size)
	{
		str[i] = file[i];
		i++;
	}
	str[i] = '\0';
	if (pos == 1)
	{
		if (!verify_row_one(str, size))
			return (0);
		rows = get_rows_one(str, size);
		if (rows == 0)
			return (0);
		if (!ft_verify_file_rows(file, rows))
			return (0);
	}
	if (pos == 2)
	{
		*columns = size;
		if (*columns == 0)
			return (0);
	}
	if (pos >= 3)
		if (*columns != size)
			return (0);
	//ft_putstr(str);
	free(str);
	return (1);
}

int	ft_verify_file_aux(char *file, int *size, int *pos, int *columns)
{
	if ((*file == '\n') || (*(file + 1) == '\0'))
	{
		*pos = *pos + 1;
		if (*(file + 1) == '\0')
		{
			file++;
			if (!ft_verify_row(file, *size + 1, *pos, columns))
				return (0);
			file--;
		}
		else
			if (!ft_verify_row(file, *size, *pos, columns))
				return (0);
		*size = -1;
	}
	return (1);
}

int	ft_verify_file(char *file)
{
	int	size;
	int	pos;
	int	columns;

	size = 0;
	pos = 0;
	columns = 0;
	while (*file)
	{
		if (!ft_verify_file_aux(file, &size, &pos, &columns))
			return (0);
		file++;
		size++;
	}
	return (1);
}
/*
int	verify_row_one(char *str, int length)
{
	char	aux;
	int	length_aux;
	int	flag;
	
	flag = 0;
	length_aux = length;
	aux = str[length_aux - 1];
	length = length_aux - 2;
	if (length_aux <4)
		return (0);
	while (length >= 0)
	{
		if (length >= (length_aux - 3))
		{
			// is imprimible

			if(!(flag == -1 && length == (length_aux - 3)))
			{
				if (aux == str[length])
				{
					ft_putstr(str);
					return (0);
				}
			}
			if ((flag == 0) && (length == (length_aux - 3)))
				flag = 1;
		}
		if (flag == 1)
		{
			flag = -1;
			aux = str[length];
			length = length_aux;
		}
		//obtener el numero y convertirlo a entero
		
		length--;
	}
	return (567);
}
*/