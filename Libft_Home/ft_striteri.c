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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f (i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>

// // Uppercase transformation
// void to_upper(unsigned int i, char *c)
// {
//     (void)i;
//     if (*c >= 'a' && *c <= 'z')
//         *c -= 32;
// }

// // Shift character by index
// void shift_by_index(unsigned int i, char *c)
// {
//     *c += i;
// }

// // Replace every character with '*'
// void mask(unsigned int i, char *c)
// {
//     (void)i;
//     *c = '*';
// }

// int main()
// {
//     char s1[10] = "hello";
//     char s2[10] = "abcd";
//     char s3[5] = "aaa";
//     s1[9] = '\0';
//     s2[9] = '\0';
//     s3[4] = '\0';

//     ft_striteri(s1, to_upper);
//     ft_striteri(s2, shift_by_index);
//     ft_striteri(s3, mask);

//     printf("%s\n", s1);
//     printf("%s\n", s2);
//     printf("%s", s3);
//     return (0);
// }