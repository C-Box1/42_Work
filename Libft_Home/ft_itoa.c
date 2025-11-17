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

static int	count_digits(long n);

char	*ft_itoa(int n)
{
	int		len;
	char	*num_st;
	long	nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	len = count_digits(nb);
	if (nb < 0)
		len++;
	num_st = malloc(sizeof(char) * (len + 1));
	if (num_st == NULL)
		return (NULL);
	num_st[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len > 0)
	{
		num_st[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		num_st[0] = '-';
	return (num_st);
}

static int	count_digits(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
// #include <stdio.h>
// #include <limits.h>

// int main()
// {
//     char *s1 = ft_itoa(0);
//     char *s2 = ft_itoa(12345);
//     char *s3 = ft_itoa(-12345);
//     char *s4 = ft_itoa(INT_MAX);
//     char *s5 = ft_itoa(INT_MIN);

//     printf("%s\n", s1);
//     printf("%s\n", s2);
//     printf("%s\n", s3);
//     printf("%s\n", s4);
//     printf("%s\n", s5);

//     free(s1);
//     free(s2);
//     free(s3);
//     free(s4);
//     free(s5);
//     return (0);
// }