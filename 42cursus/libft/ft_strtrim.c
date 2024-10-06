/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:46:35 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/06 19:00:40 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len1;
	char			*str1;
	int				i;
	int				j;
	int				k;
	int				m;

	len1 = ft_strlen(s1);
	str1 = (char *)malloc(len1);
	i = 0;
	k = 1;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	m = 1;
	while (len1 != -1)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i - 1] == set[j])
			{
				i--;
				m++;
				break ;
			}
			j++;
		}
		len1--;
	}
	j = 0;
	m = m - k;
	while (s1[k] != '\0')
	{
		str1[j++] = s1[k++];
	}
}

int main ()
{
	char const *s1 = "lolitalo";
	char const *set = "lo";

	ft_strtrim(s1, set);
}