/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:15:07 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 13:58:23 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min_node(a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_big_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if (size_a-- > 3 && !is_a_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !is_a_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_a-- > 3 && !is_a_sorted(*stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		moves_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		moves_b_to_a(stack_a, stack_b);
	}
	current_index(stack_a);
	min_to_top(stack_a);
}
