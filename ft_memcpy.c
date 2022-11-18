/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:12:39 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/09 14:20:09 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	strsize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	int			i;

	if (!dest && !src)
	{
		return (NULL);
	}
	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	while (n > 0)
	{
		cdest[i] = csrc[i];
		i++;
		n--;
	}
	return (dest);
}

/*int	main(void)
{
	char	str[10] = "Ola amigos";
	char	dest[4] = "Boas";
	printf("Source: %s\n", str);
	printf("Destination: %s\n\n", dest);
	ft_memcpy(dest, str, strsize(str));
	printf("Source: %s\n", str);
	printf("Destination: %s", dest);
	return (0);
}*/
