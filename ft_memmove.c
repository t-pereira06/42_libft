/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:14:03 by tsodre-p          #+#    #+#             */
/*   Updated: 2025/05/28 12:43:11 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	if ((!dest || !src) && n > 0)
		return (NULL);
	if (src < dest)
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else if (src > dest)
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*int	main(void)
{
	char	str[10] = "Ola amigos";
	char	dest[4] = "Boas";
	printf("Source: %s\n", str);
	printf("Destination: %s\n\n", dest);
	ft_memmove(dest, str, strsize(str));
	printf("Source: %s\n", str);
	printf("Destination: %s", dest);
	return (0);
}*/
