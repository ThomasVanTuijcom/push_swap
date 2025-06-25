/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:09 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 11:06:10 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*new_stack_node(int nbr)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->index = -1;
	node->push_cost = -1;
	node->above_median = true;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_size(t_stack_node *stack)
{
	int	length;

	length = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

t_stack_node	*stack_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	stack_add_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	last = stack_last_node(*stack);
	if (!last)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	stack_add_front(t_stack_node **stack, t_stack_node *new)
{
	if (!new)
		return ;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
