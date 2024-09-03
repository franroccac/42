/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:59:34 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/20 16:59:36 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		div;
	int		mod;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126 && !(str[i] == 127))
			write (1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			div = str[i] / 16;
			mod = str[i] % 16;
			write(1, &hexa[div], 1);
			write(1, &hexa[mod], 1);
		}
		i++;
	}
}

/*
int main(void)
{
	char str[] = "Coucou\ntu vas bi\een ?";

	ft_putstr_non_printable(str);
	return (0);
}
*/