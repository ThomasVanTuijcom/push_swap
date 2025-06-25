/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:58:04 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/19 12:25:19 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_invalid_arg(char *base)
{
	int		i;
	int		j;
	int		invalid_arg;

	i = 0;
	invalid_arg = 0;
	while (base[i] && !invalid_arg)
	{
		if (base[i] == 43 || base[i] == 45)
			invalid_arg = 1;
		j = i + 1;
		while (base[j] && !invalid_arg)
		{
			if (base[i] == base[j])
				invalid_arg = 1;
			j++;
		}
		i++;
	}
	if (i < 2)
		invalid_arg = 1;
	return (invalid_arg);
}

int	ft_putnbr_hex(int nbr, char *base)
{
	int				count;
	unsigned int	number;

	count = 0;
	number = (unsigned int) nbr;
	if (!(check_invalid_arg(base)))
	{
		if (number >= 16)
			count += ft_putnbr_hex(number / 16, base);
		return (count + write(1, &(base[(number % 16)]), 1));
	}
	return (-1);
}
