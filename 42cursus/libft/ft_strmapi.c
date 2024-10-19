/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:46:15 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/06 17:46:17 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    unsigned int    i;
    unsigned int    len;

    str = &s;
    str = (char *)malloc(ft_strlen(s + 1));
    i = 0;
    while (str[i])
    {
        f(i, &str[i]);
        i++;
    }
    return (*str);
}