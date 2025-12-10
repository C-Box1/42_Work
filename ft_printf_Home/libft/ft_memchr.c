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

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		cn;
	size_t				i;

	str = s;
	cn = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cn)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char *data = "X.Y.Z.\0A.B.C.";
//     size_t len = 12;
//     printf("'A' %td\n", (char *)ft_memchr(data, 'A', len) - data);
//     printf("'X' %td\n", (char *)ft_memchr(data, 'X', len) - data);
// 	printf("'Z' %td\n", (char *)ft_memchr(data, 'Z', 5) - data);

//     return 0;
// }