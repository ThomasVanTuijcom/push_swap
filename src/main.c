/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:25:55 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 14:37:41 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		error_msg("Usage: ./push_swap \"5 3...\" or ./push_swap 1 5...\n");
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (!argv)
		error_msg("Error getting arguments\n");
	if (init_stack_a(&a, argv) || !argv)
	{
		free_all(&a, &b, argc, argv);
		return (1);
	}
	if (!is_a_sorted(a))
		sort(&a, &b);
	free_all(&a, &b, argc, argv);
	return (0);
}
