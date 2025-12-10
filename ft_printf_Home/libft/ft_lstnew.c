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

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
//     char *text = "Hello, Charbel!";
//     t_list *node = ft_lstnew(text);

//     if (node)
//     {
//         printf("Node content: %s\n", (char *)node->content);
//         printf("Next pointer: %p\n", (void *)node->next);
//     }
//     else
//     {
//         printf("Node creation failed.\n");
//     }

//     free(node);

//     return 0;
// }