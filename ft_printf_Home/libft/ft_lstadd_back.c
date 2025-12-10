/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csahyoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:25:24 by csahyoun          #+#    #+#             */
/*   Updated: 2025/07/21 01:25:27 by csahyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list *list = NULL;

// 	t_list *n1 = ft_lstnew("first");
// 	ft_lstadd_back(&list, n1);
// 	print_list(list);

// 	t_list *n2 = ft_lstnew("second");
// 	ft_lstadd_back(&list, n2);
// 	print_list(list);

// 	t_list *n3 = ft_lstnew("third");
// 	ft_lstadd_back(&list, n3);
// 	print_list(list);
// 	t_list *tmp;
// 	while (list)
// 	{
// 		tmp = list->next;
// 		free(list);
// 		list = tmp;
// 	}
// 	return (0);
// }