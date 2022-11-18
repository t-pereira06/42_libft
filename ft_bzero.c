/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:54:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/03 10:54:21 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p;

	p = str;
	n++;
	while (--n)
	{
		*p++ = 0;
	}
}

/*int	main(void)
{
	char	arr[8] = "ABCDefgh";
	printf("String: %s\n", arr);
	ft_bzero(arr, 2);
	printf("Return: %s", arr);
	return (0);
}*/
