/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:43:50 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/05/07 14:16:51 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "limits.h"
#include "stdbool.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Operations
void					swap(t_stack_node **stack);
void					push(t_stack_node **put_stack,
							t_stack_node **take_stack);
void					rotate(t_stack_node **stack);
void					rev_rotate(t_stack_node **stack);

// Instructions
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// Rotate
void					rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, t_stack_node *cheapest);
void					rev_rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, t_stack_node *cheapest);

// Moves
void					moves_a_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					moves_b_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Error handling
int						error_msg(char *str);

// Sort
void					sort_three(t_stack_node **stack_a);
void					sort(t_stack_node **stack_a, t_stack_node **stack_b);
void					sort_big_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Stack
int						stack_size(t_stack_node *stack);
t_stack_node			*new_stack_node(int nbr);
t_stack_node			*stack_last_node(t_stack_node *stack);
void					stack_add_back(t_stack_node **stack, t_stack_node *new);
void					stack_add_front(t_stack_node **stack,
							t_stack_node *new);

// Nodes init
void					init_nodes_a(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					init_nodes_b(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Initialize
int						init_stack_a(t_stack_node **a, char **argv);

// Utils
t_stack_node			*find_min_node(t_stack_node **stack);
t_stack_node			*find_max_node(t_stack_node **stack);
t_stack_node			*get_cheapest(t_stack_node **stack);
void					current_index(t_stack_node **stack);
void					print_stack(t_stack_node *stack);
bool					is_a_sorted(t_stack_node *stack);

// Free
void					free_all(t_stack_node **a, t_stack_node **b, int argc,
							char **argv);
