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
	char	*str;

	len1 = ft_strlen(s1);
	str = (char *)malloc(len1 -);
	while ()
}