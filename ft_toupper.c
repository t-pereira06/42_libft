/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:35 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/03 15:10:36 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int a)
{
	if ((a >= 'a' && a <= 'z'))
	{
		return (a - 32);
	}
	else
		return (a);
}

/*int	main(void)
{
	char    str = 'a';

	printf("String: %c\n", str);
	printf("Return: %c\n", ft_toupper(str));
	return (0);
}*/
