/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:17:29 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/22 20:17:32 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		res = s1[i] - s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (res);
}

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	int				diff;
	unsigned int	len_needle;
	unsigned int	len_haystack;

	len_needle = ft_strlen(to_find);
	if (len_needle == 0)
		return (str);
	i = 0;
	diff = 0;
	len_haystack = ft_strlen(str);
	if (len_needle <= len_haystack)
	{
		while (str[i] != '\0')
		{
			if (str[i] == to_find[0])
			{
				diff = ft_strncmp(&str[i], to_find, len_needle);
				if (diff == 0)
					return (&str[i]);
			}
			i++;
		}
	}
	return ("");
}

/*
int main(void)
{
   char    *haystack = "Hola Mundo";
   char    *needle4 = "Mundo";

   printf("%s", ft_strstr(haystack, needle4));
}
*/