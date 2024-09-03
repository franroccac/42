/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:24:39 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/14 22:24:41 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;
	int	d;

	c = *a / *b;
	d = *a % *b;
	*a = c;
	*b = d;
}
/*
int main(void)
{
	int a;
	int b;
	a = 5;
	b = 10;
	ft_ultimate_div_mod(&a, &b);
	printf("%d, %d", a, b);
	return (0);
}
*/