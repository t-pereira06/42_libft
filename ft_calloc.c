/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:40 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/07 15:22:41 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*arr;
	size_t			i;
	unsigned int	total;

	i = 0;
	total = nitems * size;
	arr = malloc(nitems * size);
	if (arr == NULL)
		return (NULL);
	while (total > 0)
	{
		arr[i] = 0;
		total--;
		i++;
	}
	return ((void *)arr);
}

/*int	main(void)
{
	printf("Return: %s", (char *)ft_calloc(5, 4));
}*/
