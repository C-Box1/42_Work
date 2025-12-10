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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	best_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len < s_len - start)
		best_len = len;
	else
		best_len = s_len - start;
	sub = malloc(best_len + 1);
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, best_len);
	sub[best_len] = '\0';
	return (sub);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[20] = "Hello World";
//     char str2[10] = "Test";
//     char str3[5] = "";
//     str1[19] = '\0';
//     str2[9] = '\0';
//     str3[4] = '\0';

//     char *sub1 = ft_substr(str1, 6, 5);
//     char *sub2 = ft_substr(str1, 20, 5);
//     char *sub3 = ft_substr(str1, 4, 50);
//     char *sub4 = ft_substr(str3, 0, 5);
//     char *sub5 = ft_substr(str2, 1, 2);

//     printf("%s\n", sub1);  // "World"
//     printf("%s\n", sub2);  // ""
//     printf("%s\n", sub3);  // "o World"
//     printf("%s\n", sub4);  // ""
//     printf("%s", sub5);    // "es"
//     free(sub1);
//     free(sub2);
//     free(sub3);
//     free(sub4);
//     free(sub5);
//     return (0);
// }