/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:38:01 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:07 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max_node(t_stack_node **stack)
{
	t_stack_node	*max_node;
	t_stack_node	*current;

	if (!stack || !*stack)
		return (NULL);
	max_node = *stack;
	current = *stack;
	while (current)
	{
		if (current->nbr > max_node->nbr)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_stack_node	*find_min_node(t_stack_node **stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;

	if (!stack || !*stack)
		return (NULL);
	min_node = *stack;
	current = *stack;
	while (current)
	{
		if (current->nbr < min_node->nbr)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node	*get_cheapest(t_stack_node **stack)
{
	t_stack_node	*current;

	if (!stack || !*stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	current_index(t_stack_node **stack)
{
	int				i;
	int				med;
	t_stack_node	*curr;

	if (!stack || !*stack)
		return ;
	med = stack_size(*stack) / 2;
	i = 0;
	curr = *stack;
	while (curr)
	{
		curr->index = i;
		if (i <= med)
			curr->above_median = true;
		else
			curr->above_median = false;
		i++;
		curr = curr->next;
	}
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		ft_printf("value: %d, index: %d\n", stack->nbr, stack->index);
		stack = stack->next;
	}
	ft_printf("---------------\n");
}
