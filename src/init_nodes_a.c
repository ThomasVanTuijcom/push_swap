/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:23:47 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 13:11:21 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*curr_a;
	t_stack_node	*curr_b;
	t_stack_node	*target;
	long			lower_value;

	curr_a = *stack_a;
	while (curr_a)
	{
		lower_value = LONG_MIN;
		curr_b = *stack_b;
		while (curr_b)
		{
			if (curr_b->nbr > lower_value && curr_b->nbr < curr_a->nbr)
			{
				lower_value = curr_b->nbr;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (lower_value == LONG_MIN)
			curr_a->target_node = find_max_node(stack_b);
		else
			curr_a->target_node = target;
		curr_a = curr_a->next;
	}
}

static void	cost_analysis_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*curr;

	len_a = stack_size(*stack_a);
	len_b = stack_size(*stack_b);
	curr = *stack_a;
	while (curr)
	{
		curr->push_cost = curr->index;
		if (!(curr->above_median))
			curr->push_cost = len_a - curr->index;
		if (curr->target_node->above_median)
			curr->push_cost += curr->target_node->index;
		else
			curr->push_cost += len_b - curr->target_node->index;
		curr = curr->next;
	}
}

static void	set_cheapest(t_stack_node **stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;
	t_stack_node	*curr;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	cheapest_node = *stack;
	cheapest_value = LONG_MAX;
	while (curr)
	{
		if (curr->push_cost < cheapest_value)
		{
			cheapest_node = curr;
			cheapest_value = curr->push_cost;
		}
		curr = curr->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
