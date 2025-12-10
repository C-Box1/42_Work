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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst ->content);
	free(lst);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	char *str = strdup("to be deleted");
// 	t_list *node = ft_lstnew(str);
// 	printf("Before deletion: %s\n", (char *)node->content);
// 	ft_lstdelone(node, del_content);
// 	node = NULL;
// 	printf("Node deleted: %s\n", (char *)node->content);
// 	return (0);
// }