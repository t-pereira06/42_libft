/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:05:54 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/09 14:12:54 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (0);
	a = 0;
	while (big[a] != '\0' && a < len)
	{
		b = 0;
		while (big[a + b] != '\0' && big[a + b] == little[b]
			&& (a + b) < len && little[b] != '\0')
		{
			if (little[b + 1] == '\0')
			{
				return ((char *)&(big[a]));
			}
			b++;
		}
		a++;
	}
	return (0);
}

/*int	main(void)
{
	char	big[] = "Tudo bem";
	char	little[] = "o";
	printf("\n%s\n", ft_strnstr(big, little, 5));
	printf("\n%s\n", ft_strnstr(big, little, 0));
}*/
