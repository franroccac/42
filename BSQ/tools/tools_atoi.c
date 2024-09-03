


#include <unistd.h>

int	ft_strtoint_aux(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		str++;
		if (*str != '\0')
		{
			str--;
			result = (result + (*str - '0')) * 10;
		}
		else
		{
			str--;
			result = result + (*str - '0');
		}
		str++;
	}
	return (result);
}

int	ft_strtoint(char *str)
{
	int	flag;
	int	result;

	flag = 0;
	result = 0;
	if (*str == '-')
	{
		flag = 1;
		str++;
		result = ft_strtoint_aux(str);
	}
	else
	{
		result = ft_strtoint_aux(str);
	}
	if (flag)
	{
		result = result * (-1);
	}
	return (result);
}
/*void	ft_putint(int num);
int	main(void)
{
	char	prueba[] = "-2545";
	ft_putint(ft_strtoint(prueba));
}*/