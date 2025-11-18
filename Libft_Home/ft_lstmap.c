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

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// void *to_upper(void *content)
// {
// 	char *str = (char *)content;
// 	char *new = strdup(str);
// 	if (!new)
// 		return NULL;
// 	for (int i = 0; new[i]; i++)
// 		new[i] = toupper(new[i]);
// 	return new;
// }

// void del_content(void *content)
// {
// 	free(content);
// }

// void print_list(t_list *lst)
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
// 	t_list *original = NULL;
// 	ft_lstadd_back(&original, ft_lstnew(strdup("apple")));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("banana")));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("cherry")));
// 	printf("Original list:\n");
// 	print_list(original);
// 	t_list *mapped = ft_lstmap(original, to_upper, del_content);
// 	printf("Mapped list:\n");
// 	print_list(mapped);
// 	ft_lstclear(&original, del_content);
// 	ft_lstclear(&mapped, del_content);
// 	return (0);
// }