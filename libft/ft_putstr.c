/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:22:07 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/19 12:25:24 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	else
	{
		while (*s)
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	return (count);
}
