/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:46:15 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/20 03:10:17 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		f(i, str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}