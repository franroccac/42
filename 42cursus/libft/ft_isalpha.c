/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:49:14 by frocca-c          #+#    #+#             */
/*   Updated: 2024/09/17 20:49:19 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

int main (void)
{
	char c;
	c = 'a';
	printf("%d", ft_isalpha(c));
	c = 'a';
	printf("%d", isalpha(c));
	c = '1';
	printf("%d", ft_isalpha(c));
	c = '1';
	printf("%d", isalpha(c));
}