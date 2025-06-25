/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:43:17 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 14:19:49 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	clear_stack(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*next;

	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}

void	free_all(t_stack_node **a, t_stack_node **b, int argc, char **argv)
{
	if (argc == 2)
		free_array((void **)argv);
	clear_stack(a);
	clear_stack(b);
}
