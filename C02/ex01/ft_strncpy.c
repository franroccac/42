/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:50 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/21 21:47:35 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (i >= ft_strlen(src))
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
	char a[50];
	char *b;
	unsigned int n;


	n = 12;
	b = "Hola mundo";
	ft_strncpy(a, b, n);
	printf("%s", a);
	return (0);
}
*/
