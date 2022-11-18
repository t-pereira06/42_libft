/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:59:15 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/04 15:59:16 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str1[20] = "bomdiaaa";
	char str2[20] = "Ola";
	char str3[20] = "bomdiaaa";

	printf("Primeira String: %s", str1);
	printf("\nSegunda String: %s", str3);
	printf("\nReturn: %d", (int)ft_memcmp(str1, str3, 5));
}*/
