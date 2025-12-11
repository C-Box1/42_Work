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

int	ft_decToHex (unsigned int nb, char c)
{
	int		count;
	char	*hexDigits;

	hexDigits = NULL;
	if (c == 'x')
		hexDigits = "0123456789abcdef";
	else if (c == 'X')
		hexDigits = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_decToHex(nb / 16, c);
	ft_put_char(hexDigits[nb % 16]);
	count++;
	return (count);
}
