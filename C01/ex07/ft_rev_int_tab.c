/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:04:05 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/15 18:04:10 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	fin;
	int	temp;

	i = 0;
	fin = size - 1;
	while (i <= fin)
	{
		temp = tab[fin];
		tab[fin] = tab[i];
		tab[i] = temp;
		fin--;
		i++;
	}
}
/*
int main(void)
{
	int a[] = {1, 2, 8, 4, 5};
	int size = 5; 
	int i = 0;
	ft_rev_int_tab(a, size);
    while (i < size)
    {
        printf("%d ", a[i]);
        i++;
    }
	return (0);
}
*/