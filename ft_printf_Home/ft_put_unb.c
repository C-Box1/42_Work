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

#include "ft_printf.h"

static int	count_digits(unsigned int n);

int	ft_put_unb(unsigned int n)
{
	int				len;
	char			*num_st;
	unsigned int	nb;
	int				count;

	nb = n;
	len = count_digits(nb);
	num_st = malloc(sizeof(char) * (len + 1));
	if (num_st == NULL)
		return (0);
	num_st[len] = '\0';
	while (len > 0)
	{
		num_st[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	count = ft_put_string(num_st);
	free(num_st);
	return (count);
}

static int	count_digits(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
