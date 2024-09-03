/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:05:05 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/26 21:05:07 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_change_char_int(char **arr)
{
	int	**arr_int;
	int	x;
	int	y;
	int	i;

	y = (sizeof(arr) / sizeof(arr[0]));
	x = (sizeof(arr[0]) / sizeof(arr[0][0]));
	**arr_int = malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		arr_int[i] = malloc(sizeof(int) * y);
		i++;
	}
	y = 0;
	x = 0;
	while (arr[x][y] != '\0')
	{
		x = 0;
		while (*arr[x] != '\0')
		{
			if (arr[x][y] == '.')
				arr_int[x][y] = 0;
			else if (arr[x][y] == 'o')
				arr_int[x][y] = -1;
			x++;
		}
		y++;
	}
	return (arr_int);
}

void	ft_reverse(char **arr, int **arr_int, char fill)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (arr[x][y] != '\0')
	{
		x = 0;
		while (*arr[x] != '\0')
		{
			if (arr_int[x][y] >= 0)
				arr[x][y] = '.';
			else if (arr_int[x][y] == -1)
				arr[x][y] = 'o';
			else if (arr_int[x][y] == -2)
				arr[x][y] = 'x';
			x++;
		}
		y++;
	}
}