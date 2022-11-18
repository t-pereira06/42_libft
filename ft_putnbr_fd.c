/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:19:26 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/10 11:57:23 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0 || n > 2147483647)
		return ;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + 48), fd);
		return ;
	}
	ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10 + 48), fd);
}

/*int		main(void)
{
	ft_putnbr_fd(450, 1);
	return (0);
}*/
