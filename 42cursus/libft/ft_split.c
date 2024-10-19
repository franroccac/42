/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:45:36 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/19 21:54:12 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	while (s[i])
	{
		if (s[i] = c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	strndup()

char **ft_split(char const *s, char c)
{
	
}