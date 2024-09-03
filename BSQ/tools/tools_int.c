/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvera <bvera@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:09:29 by bvera             #+#    #+#             */
/*   Updated: 2024/08/27 04:09:31 by bvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char1(char n)
{
	write(1, &n, 1);
}

void	ft_putint_aux(int num)
{
	if (num != 0)
	{
		ft_putint_aux(num / 10);
		print_char1((num % 10) + '0');
	}
}

void	ft_putint(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		ft_putint_aux(num);
	}
	write(1, "\n", 1);
}
