/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:45:36 by frocca-c          #+#    #+#             */
/*   Updated: 2024/10/20 03:00:54 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t		i;
	char		*dest;

	dest = (char *)malloc(n + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (i <= n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	new_word;
	size_t	count;

	i = 0;
	new_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && new_word == 0)
		{
			new_word = 1;
			count++;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (count);
}

static char	**ft_free(char **array, size_t j)
{
	while (j > 0)
	{
		free(array[j - 1]);
		j--;
	}
	free(array);
	return (NULL);
}

static char	**str_split(char **str, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
		{
			str[j] = ft_strndup(s + start, i - start);
			i++;
			if (!str[j])
				ft_free(str, j);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(word_count(s, c) + 1);
	if (!str)
		return (NULL);
	return (str_split(str, s, c));
}
/*
#include <stdio.h>
int main ()
{
	char str[] = "hello people this is me";
	char **words = ft_split(str, ' ');

	int i = 0;
	while (words[i] != NULL)
	{
		printf("word %d: %s\n", i, words[i]);
		free (words[i]);
		i++;
	}
	free (words);
	return (0);
}*/