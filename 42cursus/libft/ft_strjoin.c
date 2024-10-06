#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	unsigned int	j;
	char			*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2);
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = "";
	char *s2 = "mundo!";

	printf("Concatenar: %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/