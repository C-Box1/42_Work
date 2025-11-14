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

void	*ft_bzero(void *ptr, size_t n)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)ptr;
	while (n > 0)
	{
		p[i] = '\0';
		i++;
		n--;
	}
	return (ptr);
}
// #include <stdio.h>
// int main()
// {
// 	char	c[12] = "Hello World";
// 	c [11] = '\0';
// 	printf("%s", (char *)ft_bzero(c, 5));
// }