/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:17:42 by tsodre-p          #+#    #+#             */
/*   Updated: 2022/11/10 16:27:31 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	int	size = 0;
	t_list *head;
	t_list *new;
	t_list *new2;
	t_list *new3;

	head = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	new2 = malloc(sizeof(t_list));
	new3 = malloc(sizeof(t_list));

	head->content = (char *)"head";
	head->next = NULL;
	new->content = (char *)"new";
	new->next = NULL;
	new2->content = (char *)"new2";
	new2->next = NULL;
	new3->content = (char *)"new3";
	new3->next = NULL;
	ft_lstadd_front(&head, new);
	ft_lstadd_front(&new, new2);
	ft_lstadd_front(&new2, new3);
	size = ft_lstsize(new3);
	printf("%i\n", size);
	return 0;
}*/
