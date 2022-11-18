/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:11 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/10 11:32:36 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void my_func(unsigned int i, char *c)
{
	printf("index = %d and %c\n", i, *c);
}
int main()
{
	char str[] = "ola querido";
	puts(str);
	ft_striteri(str, my_func);
	puts(str);
	return (0);
}*/
