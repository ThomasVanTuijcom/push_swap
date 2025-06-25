/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:58:04 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/19 12:25:13 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_dec(int nbr)
{
	int		count;
	char	digit;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			count++;
		}
		if (nbr >= 10)
			count += ft_putnbr_dec(nbr / 10);
		digit = (nbr % 10) + '0';
		return (count + write(1, &digit, 1));
	}
	return (-1);
}
