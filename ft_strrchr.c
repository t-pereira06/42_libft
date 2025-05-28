/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:54:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2025/05/28 20:36:39 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (0);
}

/*int	main(void)
{
	char	str[] = "suspensao";
	printf("String: %s\n", str);
	printf("Return: %s", ft_strrchr(str, 's'));
}*/
