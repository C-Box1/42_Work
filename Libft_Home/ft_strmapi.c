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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new_s;
	unsigned int	i;

	if(s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = f (i, s[i]);
		i++;
	}
	new_s[len] = '\0';
	return (new_s);
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Sample transformation: uppercase
char to_upper(unsigned int i, char c)
{
    (void)i;
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

// Sample transformation: shift by index
char shift_by_index(unsigned int i, char c)
{
    return c + i;
}

// Sample transformation: identity
char identity(unsigned int i, char c)
{
    (void)i;
    return c;
}

int main()
{
    char s1[20] = "hello";
    char s2[10] = "abcd";
    char s3[5] = "";
    s1[19] = '\0';
    s2[9] = '\0';
    s3[4] = '\0';

    char *map1 = ft_strmapi(s1, to_upper);
    char *map2 = ft_strmapi(s2, shift_by_index);
    char *map3 = ft_strmapi(s1, identity);
    char *map4 = ft_strmapi(s3, to_upper);

    printf("%s\n", map1);
    printf("%s\n", map2);
    printf("%s\n", map3);
    printf("%s", map4);

    free(map1);
    free(map2);
    free(map3);
    free(map4);

    return (0);
}