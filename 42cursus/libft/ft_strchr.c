/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:45:41 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/06 17:45:42 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while ((*str != '\0') && (*str != (char)c))
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}