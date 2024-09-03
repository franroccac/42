/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:37:39 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/19 19:37:41 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	char	*wer;
	char	*num_str;
	char	*null;

	wer = "\n";
	num_str = "HOLA";
	null = "";
	ft_str_is_printable(num_str);
	printf("%d\n", ft_str_is_printable(wer));
}
*/