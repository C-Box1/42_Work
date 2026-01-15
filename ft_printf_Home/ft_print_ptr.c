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

static int	ft_put_hex(unsigned long long nb, char *hexDigits);

int	ft_print_ptr(unsigned long long nb)
{
	int		count;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (nb == 0)
	{
		ft_put_string("(nil)");
		return (5);
	}
	ft_put_string("0x");
	count = 2;
	count += ft_put_hex(nb, hex_digits);
	return (count);
}

static int	ft_put_hex(unsigned long long nb, char *hexDigits)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_put_hex(nb / 16, hexDigits);
	ft_put_char(hexDigits[nb % 16]);
	count++;
	return (count);
}
