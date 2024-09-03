/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:51:05 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/11 19:32:22 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	print_char(int x, int y, int r, int f)
{
	if ((r == 1 && f == 1) || (r == x && f == y && r != 1 && f != 1))
		ft_putchar('/');
	else if ((r == x && f == 1) || (r == 1 && f == y))
		ft_putchar('\\');
	else if ((f == 1 && r != x) || (f == y && r != x))
		ft_putchar('*');
	else if ((r == 1 && f != y) || (r == x && f != y))
		ft_putchar('*');
	else if (r != 1 && r != x)
		ft_putchar(' ');
}

void	rush01(int x, int y)
{
	char	r;
	char	f;

	if (x < 1 || y < 1)
		write(1, "Los numeros deben de ser positivos, por favor :D\n", 49);
	f = 1;
	while (f <= y)
	{
		r = 1;
		while (r <= x)
		{
			print_char(x, y, r, f);
			r = r + 1;
		}
		ft_putchar('\n');
		f = f + 1;
	}
}
