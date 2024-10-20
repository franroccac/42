/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:43 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/20 03:18:19 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numcount(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nb;
	char	sign;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numcount(n);
	nb = (char *)malloc(len + 1);
	if (!nb)
		return (NULL);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	nb[len] = '\0';
	while (len-- > 0)
	{
		nb[len - 1] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		nb[0] = '-';
	return (nb);
}

#include <stdio.h>
int main()
{
	int n = -2147483648;

	printf("%s", ft_itoa(n));
}