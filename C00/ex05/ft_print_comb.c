/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:09:51 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/10 12:11:58 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char n, char u, char m)
{
	write(1, &n, 1);
	write(1, &u, 1);
	write(1, &m, 1);
	if (n != '7' || u != '8' || m != '9')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	n;
	char	u;
	char	m;

	n = '0';
	while (n <= '7')
	{
		u = n + 1;
		while (u <= '8')
		{
			m = u + 1;
			while (m <= '9')
			{
				if (n != u && n != m && m != u)
					print_num(n, u, m);
				m++;
			}
			u++;
		}
		n++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}
*/