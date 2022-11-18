/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:54:42 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/09 17:13:01 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (src_size + size);
	while (dest_size < (size - 1) && src[i] != '\0')
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	return (src_size + ft_strlen(dest) - i);
}

/*int	main(void)
{
	char	arr1[25] = "amanha";
	char	arr2[25] = "ola";

	printf("Source: %s\n", arr1);
	printf("Destination: %s\n", arr2);
	printf("Caracteres: %zu\n", ft_strlcat(arr2, arr1, 41));
	printf("Source: %s\n", arr1);
	printf("Destination: %s\n", arr2);
	return (0);
}*/
