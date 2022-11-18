/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:19:04 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/10 11:32:27 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	i = 0;
	if (!s || !f)
		return (NULL);
	string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*char my_func(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
	return (str);
}

int		main(void)
{
	char	str[] = "ola deus";
	printf("String: %s\n", str);
	printf("Return: %s\n", ft_strmapi(str, my_func));
}*/
