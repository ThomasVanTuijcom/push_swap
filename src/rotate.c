/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:15 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 13:58:39 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rr(stack_a, stack_b);
	current_index(stack_a);
	current_index(stack_b);
}

void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrr(stack_a, stack_b);
	current_index(stack_a);
	current_index(stack_b);
}
