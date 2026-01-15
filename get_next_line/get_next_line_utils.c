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

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (str == NULL)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*dup;
	size_t		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		dup[i] = s[i++];
	dup[len] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	best_len;
	size_t	i;

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
	i = 0;
	while (i < best_len)
		sub[i] = s[start + i++];
	sub[best_len] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*big_s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (SIZE_MAX - len1 < len2 + 1)
		return (NULL);
	big_s = malloc(len1 + len2 + 1);
	if (big_s == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		big_s[i] = s1[i];
	len1 = i;
	i = -1;
	while (s2[++i])
		big_s[len1 + i] = s2[i];
	big_s[len1 + i] = '\0';
	return (big_s);
}
