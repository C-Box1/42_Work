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

static int	check_index(char spec, va_list list);

int	ft_printf(const char *start, ...)
{
	va_list		list;
	const char	*index;
	int			count;

	va_start(list, start);
	index = start;
	count = 0;
	while (*index != '\0')
	{
		if (*index == '%' && *(index + 1) != '\0')
		{
			index++;
			count += check_index(*index, list);
		}
		else
			count += ft_put_char(*index);
		index++;
	}
	va_end(list);
	return (count);
}

static int	check_index(char spec, va_list list)
{
	if (spec == 'c')
		return (ft_put_char(va_arg(list, int)));
	if (spec == 's')
		return (ft_put_string(va_arg(list, char *)));
	if (spec == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(list, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_put_nbr(va_arg(list, int)));
	if (spec == 'u')
		return (ft_put_unb(va_arg(list, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_decToHex(va_arg(list, unsigned int), spec));
	if (spec == '%')
		return (ft_put_char('%'));
	return (0);
}
