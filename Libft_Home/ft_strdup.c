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

char	*ft_strdup(const char *s)
{
	size_t		total_size;
	void		*dup;
	void		*src;

	src = (void *)s;
	total_size = ft_strlen(src) + 1;
	dup = malloc(total_size);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, src, total_size);
	return (dup);
}
