/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:54:42 by tsodre-p          #+#    #+#             */
/*   Updated: 2025/05/28 20:26:52 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	if (!src)
		return (0);
	if (!dest)
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (size + src_size);
	i = 0;
	while (src[i] && (dest_size + i) < (size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
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
