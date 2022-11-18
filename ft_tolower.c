/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:13:10 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/03 15:13:11 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int a)
{
	if ((a >= 'A' && a <= 'Z'))
	{
		return (a + 32);
	}
	else
		return (a);
}

/*int	main(void)
{
	char    str = 'A';

	printf("String: %c\n", str);
	printf("Return: %c\n", ft_tolower(str));
	return (0);
}*/
