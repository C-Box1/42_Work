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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include "libft.h"

// // Helper function to print the list contents
// void print_list(t_list *head)
// {
//     while (head)
//     {
//         printf("%s -> ", (char *)head->content);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// int main(void)
// {
//     t_list *node1 = ft_lstnew("World");
//     t_list *node2 = ft_lstnew("Beautiful");
//     t_list *node3 = ft_lstnew("Hello");

// 	t_list *head = NULL;
//     ft_lstadd_front(&head, node1);
//     ft_lstadd_front(&head, node2);
//     ft_lstadd_front(&head, node3);
//     print_list(head);

//     return 0;
// }