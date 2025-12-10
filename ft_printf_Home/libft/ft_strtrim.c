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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_len;
	char	*trim_str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim_len = end - start;
	trim_str = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (trim_str == NULL)
		return (NULL);
	ft_memcpy(trim_str, s1 + start, trim_len);
	trim_str[trim_len] = '\0';
	return (trim_str);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//		char s1[30] = "   Hello World   ";
//		char s2[20] = "xxHelloxx";
//		char s3[10] = "abc";
//		char s4[5] = "";
//		s1[29] = '\0';
//		s2[19] = '\0';
//		s3[9] = '\0';
//		s4[4] = '\0';

//		char *trim1 = ft_strtrim(s1, " ");
//		char *trim2 = ft_strtrim(s2, "x");
//		char *trim3 = ft_strtrim(s3, "abc");
//		char *trim4 = ft_strtrim(s4, " ");
//		char *trim5 = ft_strtrim(s1, "");

//		printf("%s\n", trim1);
//		printf("%s\n", trim2);
//		printf("%s\n", trim3);
//		printf("%s\n", trim4);
//		printf("%s", trim5);

//		free(trim1);
//		free(trim2);
//		free(trim3);
//		free(trim4);
//		free(trim5);
//		return (0);
// }