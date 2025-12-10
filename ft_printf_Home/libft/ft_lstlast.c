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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	print_last_node(t_list *lst)
// {
// 	t_list *last = ft_lstlast(lst);
// 	if (last)
// 		printf("Last node content: %s\n", (char *)last->content);
// 	else
// 		printf("List is empty.\n");
// }

// int	main(void)
// {
// 	print_last_node(NULL);
// 	t_list *node1 = ft_lstnew("first");
// 	print_last_node(node1);
// 	t_list *node2 = ft_lstnew("second");
// 	t_list *node3 = ft_lstnew("third");
// 	node1->next = node2;
// 	node2->next = node3;
// 	print_last_node(node1);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }