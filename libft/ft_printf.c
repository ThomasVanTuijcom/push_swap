/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:02:22 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/19 12:26:44 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_conversion(char specifier, va_list *argptr)
{
	if (specifier && specifier == 'c')
		return (ft_putchar((char)va_arg(*argptr, int)));
	else if (specifier && specifier == 's')
		return (ft_putstr(va_arg(*argptr, char *)));
	else if (specifier && specifier == 'p')
		return (ft_printpointer(va_arg(*argptr, void *)));
	else if (specifier && (specifier == 'd' || specifier == 'i'))
		return (ft_putnbr_dec(va_arg(*argptr, int)));
	else if (specifier && specifier == 'u')
		return (ft_printunsigned((unsigned int)va_arg(*argptr, int)));
	else if (specifier && specifier == 'x')
		return (ft_putnbr_hex(va_arg(*argptr, int), "0123456789abcdef"));
	else if (specifier && specifier == 'X')
		return (ft_putnbr_hex(va_arg(*argptr, int), "0123456789ABCDEF"));
	else
		return (ft_putchar(specifier));
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		length;

	length = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			length += print_conversion(*str, &argptr);
		}
		else
			length += ft_putchar(*str);
		str++;
	}
	va_end(argptr);
	return (length);
}
