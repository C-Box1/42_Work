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

static int check_index(char spec, va_list list);

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

static int check_index(char spec, va_list list)
{
	if (spec == 'c')
		return (ft_put_char(va_arg(list, int)));
	if (spec == 's')
		return (ft_put_string(va_arg(list, char *)));
	if(spec == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(list, void *)));
	if(spec == 'd' || spec == 'i')
		return (ft_put_nbr(va_arg(list, int)));
	if(spec == 'u')
		return (ft_put_unb(va_arg(list, unsigned int)));
	if(spec == 'x' || spec == 'X')
		return (ft_decToHex(va_arg(list, unsigned int), spec));
	if(spec == '%')
		return (ft_put_char('%'));
	return (0);
}

// #include <stdio.h>
// #include "ft_printf.h"

// int main(void)
// {
//     int a, b;
//     char *str = "world";
//     int num = 42;
//     void *ptr = &num;

//     a = printf("Hello %s %d %u %x %X %p %%\n", str, num, num, num, num, ptr);
//     b = ft_printf("Hello %s %d %u %x %X %p %%\n", str, num, num, num, num, ptr);

//     printf("printf returned: %d\n", a);
//     printf("ft_printf returned: %d\n", b);

//     // Test NULL pointer
//     a = printf("NULL pointer: %p\n", NULL);
//     b = ft_printf("NULL pointer: %p\n", NULL);
//     printf("printf returned: %d\n", a);
//     printf("ft_printf returned: %d\n", b);

//     return 0;
// }