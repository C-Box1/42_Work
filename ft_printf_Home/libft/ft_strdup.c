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

char	*ft_strdup(const char *s)
{
	size_t		total_size;
	char		*dup;

	total_size = ft_strlen(s) + 1;
	dup = malloc(total_size);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, total_size);
	return (dup);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[20] = "Hello World";
//     char str2[10] = "Test";
//     char str3[10] = " ";
//     str1[19] = '\0';
//     str2[9] = '\0';
//     char *dup1 = ft_strdup(str1);
//     char *dup2 = ft_strdup(str2);
//     char *dup3 = ft_strdup(str3);
//     printf("%s\n", dup1);
//     printf("%s\n", dup2);
// 	printf("%s", dup3);
//     free(dup1);
//     free(dup2);
// 	free(dup3);
//     return (0);
// }