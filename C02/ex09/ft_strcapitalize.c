/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:20:58 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/20 16:21:00 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	print_str(char *str, int i, int j)
{
	if (!((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[j] >= 'a' && str[j] <= 'z')
			str[j] = str[j] - 32;
	}
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
			str[i] = str[i] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		print_str(str, i, j);
		i++;
		j++;
	}
	return (str);
}

/*
int main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(str));
}
*/