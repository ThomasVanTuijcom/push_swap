/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:16:13 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 13:58:34 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prep_a_for_push(t_stack_node **a, t_stack_node *top)
{
	while (*a != top)
	{
		if (top->above_median)
			ra(a);
		else
			rra(a);
	}
}

static void	prep_b_for_push(t_stack_node **b, t_stack_node *top)
{
	while (*b != top)
	{
		if (top->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	moves_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(stack_a);
	if (cheapest->target_node->above_median && cheapest->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->target_node->above_median && !cheapest->above_median)
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_a_for_push(stack_a, cheapest);
	prep_b_for_push(stack_b, cheapest->target_node);
	pb(stack_a, stack_b);
}

void	moves_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_a_for_push(stack_a, (*stack_b)->target_node);
	pa(stack_a, stack_b);
}
