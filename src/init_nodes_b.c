/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:23:47 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 13:14:51 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*curr_a;
	t_stack_node	*curr_b;
	t_stack_node	*target;
	long			biggest_value;

	curr_b = *stack_b;
	while (curr_b)
	{
		biggest_value = LONG_MAX;
		curr_a = *stack_a;
		while (curr_a)
		{
			if (curr_a->nbr < biggest_value && curr_a->nbr > curr_b->nbr)
			{
				biggest_value = curr_a->nbr;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (biggest_value == LONG_MAX)
			curr_b->target_node = find_min_node(stack_a);
		else
			curr_b->target_node = target;
		curr_b = curr_b->next;
	}
}

void	init_nodes_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
