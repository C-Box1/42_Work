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

int	ft_dec_to_hex(unsigned int nb, char c)
{
	int		count;
	char	*hex_digits;

	hex_digits = NULL;
	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else if (c == 'X')
		hex_digits = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_decToHex(nb / 16, c);
	ft_put_char(hex_digits[nb % 16]);
	count++;
	return (count);
}
