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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;
	size_t				i;

	s1_str = s1;
	s2_str = s2;
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

// int main() {
//     const char *data1 = "A B C \0 X Y Z";
//     const char *data2 = "A B C \0 K L M";
//     int result1 = ft_memcmp(data1, data2, 10);
//     printf("%d\n", result1);
//     int result2 = ft_memcmp(data1, data2, 7);
//     printf("%d\n", result2);
//     int result3 = ft_memcmp(data1, data2, 1);
//     printf("%d\n", result3);
//     return 0;
// }