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

	nb = (long)n;
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
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
