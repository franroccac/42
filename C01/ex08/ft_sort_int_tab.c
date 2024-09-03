/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:25:54 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/14 22:25:57 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	fin;
	int	temp;
	int	inicio;

	inicio = 0;
	temp = 0;
	fin = size - 1;
	while (inicio <= fin)
	{
		i = 0;
		while (i <= fin)
		{
			if (tab[i + 1] < tab[i])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		inicio++;
	}
}
/*
int main(void)
{
	int a[] = {5, 8, 4, 7, 4};
	int size;
	int i = 1;
	size = 5;
	ft_sort_int_tab(a, size);
    while (i <= size)
    {
        printf("%d ", a[i]);
        i++;
    }
	return (0);
}
*/