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

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	print_content(void *content)
// {
// 	printf("Visited: %s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list *list = NULL;
// 	ft_lstadd_back(&list, ft_lstnew(strdup("first")));
// 	ft_lstadd_back(&list, ft_lstnew(strdup("second")));
// 	ft_lstadd_back(&list, ft_lstnew(strdup("third")));
// 	ft_lstiter(list, print_content);
// 	ft_lstclear(&list, free);
// 	return (0);
// }