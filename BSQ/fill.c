/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:05:18 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/26 21:05:20 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fill_gaps(int **arr)
{
	int	max_x;
	int	max_y;

	max_y = (sizeof(arr) / sizeof(arr[0]));
	while (arr[max_x][max_y] != '\0')
	{
		max_x = (sizeof(arr[0]) / sizeof(arr[0][0]));
		while (*arr[max_x] != '\0')
		{
			if (arr[max_x][max_y] == -1)
				max_x--; 
			arr[max_x][max_y] = ft_fill_gaps_coor(arr, max_x, max_y);
		}
		max_y--;
	}
	return(arr)
}

int	**ft_fill_gaps_coor(int **arr, int max_x, int max_y)
{
	int	num_min;
	int	num_down;
	int	num_right;
	int	num_diago;

	num_min = 0;
	num_down = arr[max_x][max_y - 1];
	num_right = arr[max_x - 1][max_y];
	num_diago = arr[max_x - 1][max_y - 1];
	if (num_down <= num_diago && num_down <= num_right)
	{
		num_min = num_down;
		return (num_min);
	}
	else if (num_diago <= num_down && num_diago <= num_right)
	{
		num_min = num_diago;
		return (num_min);
	}
	else if (num_right <= num_down && num_right <= num_diago)
	{
		num_min = num_right;
		return (num_min);
	}
}
