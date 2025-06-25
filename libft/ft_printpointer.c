/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:58:44 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/19 12:24:52 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpointer(void *ptr)
{
	char			*hex;
	unsigned long	address;
	char			buffer[16];
	int				i;

	i = 15;
	if (!ptr)
		return (write(1, "0x0", 3));
	else
	{
		hex = ft_strdup("0123456789abcdef");
		if (!hex)
			return (-1);
		address = (unsigned long)ptr;
		while (address > 0)
		{
			buffer[i--] = hex[address % 16];
			address /= 16;
		}
		free(hex);
	}
	return (write(1, "0x", 2) + write(1, &buffer[i + 1], 16 - i - 1));
}
