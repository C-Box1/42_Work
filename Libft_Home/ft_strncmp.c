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

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;
	size_t				i;

	s1_str = (const unsigned char *)s1;
	s2_str = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_str[i] != s2_str[i])
			return ((int)(s1_str[i] - s2_str[i]));
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main() 
// {
//     const char *str1 = "apple pie";
//     const char *str2 = "apple sauce";
//     const char *str3 = "app";
//     int result1 = ft_strncmp(str1, str2, 5); 
//     printf("1. strncmp(%s, %s, 5): %d \n", str1, str2, result1);
//     int result2 = ft_strncmp(str1, str2, 7); 
//     printf("2. strncmp(%s, %s, 7): %d \n", str1, str2, result2);
//     int result3 = ft_strncmp(str1, str3, 4); 
//     printf("3. strncmp(%s, %s, 4): %d \n", str1, str3, result3);
//     return 0;
// }