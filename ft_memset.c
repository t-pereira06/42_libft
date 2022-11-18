/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:36:59 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/03 10:37:10 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n--)
	{
		*p++ = (unsigned char)c;
	}
	return (str);
}

/*int	main(void)
{
	char	arr[8] = "ABCDefgh";
	printf("String: %s\n", arr);
	ft_memset(arr, '1', 4);
	printf("Return: %s", arr);
	return (0);
}*/
