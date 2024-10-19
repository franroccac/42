/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:46:35 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/19 21:56:16 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*res;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && s1[i] == *set)
		i++;
	j = ft_strlen(s1);
	while (j > i && s1[j - 1] == *set)
		j--;
	len = j - i;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + i, len + 1);
	return (res);
}
