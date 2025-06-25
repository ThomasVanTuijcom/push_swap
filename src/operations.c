/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:12:59 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 12:31:30 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	push(t_stack_node **put_stack, t_stack_node **take_stack)
{
	t_stack_node	*top;

	if (!*take_stack)
		return ;
	top = *take_stack;
	*take_stack = top->next;
	if (*take_stack)
		(*take_stack)->prev = NULL;
	top->next = NULL;
	stack_add_front(put_stack, top);
}

void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*prev_last;

	if (stack_size(*stack) < 2)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	prev_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
