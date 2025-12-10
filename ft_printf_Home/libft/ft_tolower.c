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

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}
// #include <stdio.h>

// int main() {
//     printf("a -> %c\n", ft_tolower('a'));
//     printf("Z -> %c\n", ft_tolower('Z'));
//     printf("9 -> %c\n", ft_tolower('9'));
//     return 0;
// }