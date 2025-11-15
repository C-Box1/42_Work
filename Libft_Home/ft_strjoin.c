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

#include <stdint.h>
#include "libft.h"

static char	*check_null(char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*big_s;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL)
		return (check_null(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (SIZE_MAX - len1 < len2 + 1)
		return (NULL);
	big_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (big_s == NULL)
		return (NULL);
	ft_memcpy(big_s, s1, ft_strlen(s1));
	ft_memcpy(big_s + len1, s2, len2);
	big_s[len1 + len2] = '\0';
	return (big_s);
}

static char	*check_null(char const *s2)
{
	char	*big_s;

	if (s2 != NULL)
		return (ft_strdup(s2));
	else
	{
		big_s = malloc(1);
		*big_s = '\0';
		return (big_s);
	}
}
