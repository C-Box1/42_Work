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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char *str = "banana";
//     printf("1. 'a' found at: %td\n", ft_strchr(str, 'a') - str);
//     printf("2. 'z' found at: %p\n", (void *)ft_strchr(str, 'z'));
//     printf("3. '\\0' found at: %td\n", ft_strchr(str, '\0') - str);
//     return 0;
// }