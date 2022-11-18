/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:17:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/11 11:23:24 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int	main()
{
	t_list *head;
	t_list *new;
	if(!(head = malloc(sizeof(t_list))))
		return 0;
	if(!(new = malloc(sizeof(t_list))))
		return 0;
	head->content = (char *)"head";
	head->next = NULL;
	new->content = (char *)"new";
	new->next = NULL;
	ft_lstadd_front(&head, new);
	printf("%s\n", (char *)new->content);
	printf("%s\n\n", (char *)new->next->content);
	printf("%s\n", (char *)new->content);
	printf("%s\n", (char *)head->content);
	return 0;
}*/
