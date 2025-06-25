/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:13:12 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 14:26:27 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_int(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!str || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '\0')
			return (false);
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		num = num * 10 + (*str - '0');
		if (sign * num > INT_MAX || sign * num < INT_MIN)
			return (false);
		str++;
	}
	return (true);
}

static bool	stack_containsdouble(t_stack_node *stack, int target)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->nbr == target)
			return (true);
		stack = stack->next;
	}
	return (false);
}

int	init_stack_a(t_stack_node **a, char **args)
{
	int				i;
	int				nbr;
	t_stack_node	*new;

	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (error_msg("Values must be integers\n"));
		nbr = ft_atoi(args[i]);
		if (stack_containsdouble(*a, nbr))
			return (error_msg("The list of values contains doubles\n"));
		new = new_stack_node(nbr);
		if (!new)
			return (error_msg("Could not create new node\n"));
		stack_add_back(a, new);
		i++;
	}
	return (0);
}
