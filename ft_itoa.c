/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:08:23 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/10 10:38:09 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	plus_minus(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = size(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = plus_minus(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

/*int	main(void)
{
	printf("Return: %s\n", ft_itoa(123456789));
	printf("Return: %s\n", ft_itoa(0001057));
	printf("Return: %s\n", ft_itoa(-123456789));
	printf("Return: %s\n", ft_itoa(-000167));
	return (0);
}*/
