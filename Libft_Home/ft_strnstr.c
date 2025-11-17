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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;
	size_t	i;

	lil_len = ft_strlen(little);
	i = 0;
	if (lil_len == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (i + lil_len > len)
			break ;
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, lil_len) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char big[20] = "Hello World";
//     char little[10] = "World";
//     big[11] = '\0';
//     little[9] = '\0';
//     printf("%s\n", ft_strnstr(big, little, 11));
//     printf("%s", big);
//     return (0);
// }