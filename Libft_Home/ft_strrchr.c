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

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char *str = "banana";
//     printf(" Last 'a' found at: %td\n", ft_strrchr(str, 'a') - str); 
//     printf(" 'z' found at: %p\n", (void *)ft_strrchr(str, 'z'));
//     printf("'\\0' found at: %td\n", ft_strrchr(str, '\0') - str);
//     return 0;
// }