/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvera <bvera@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:30:45 by bvera             #+#    #+#             */
/*   Updated: 2024/08/27 04:30:48 by bvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char4(char n)
{
	write(1, &n, 1);
}

void	ft_putstr(char *str)
{
	int	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		print_char4(str[aux]);
		aux++;
	}
	write(1, "\n", 1);
}

int	is_digit(char valor)
{
	if (valor >= '0' && valor <= '9')
		return (1);
	else
		return (0);
}

int	is_print(char valor)
{
	if (valor >= 32 && valor <= 126)
		return (1);
	else
		return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	aux;

	aux = 0;
	while (*src)
	{
		dest[aux] = *src;
		src++;
		aux++;
	}
	dest[aux] = '\0';
	return (dest);
}
