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

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			i;

	p = (unsigned char *)ptr;
	v = (unsigned char)value;
	i = 0;
	while (n > 0)
	{
		p[i] = v;
		i++;
		n--;
	}
	return (ptr);
}
// #include <stdio.h>
// int main()
// {
// 	char	c[12] = "Hello World";

// 	c[11]= '\0';
// 	printf("%s", (char *)ft_memset(c, 'a', 5));
// }