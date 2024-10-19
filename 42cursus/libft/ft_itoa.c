/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:43 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/19 21:51:49 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*nb;
	int		len;

	i = 0;
	nb = (char *)malloc(len + 1);
	while (n >= 0)
	{
		nb[i] = (n / 10) + '0';
		i++;
	}
	return (nb);
}

int main()
{
	int n = 100;
	printf("%s", ft_itoa(n));
}