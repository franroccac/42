/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocca-c <frocca-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:24:52 by frocca-c          #+#    #+#             */
/*   Updated: 2024/08/19 19:24:54 by frocca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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

	wer = "287645";
	num_str = "Hola43o";
	null = "";
	ft_str_is_numeric(num_str);
	printf("%d\n",  ft_str_is_numeric(null));
}
*/