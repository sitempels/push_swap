/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:24 by stempels          #+#    #+#             */
/*   Updated: 2025/03/06 13:39:49 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_elem **stack)
{
	t_elem	*temp;
	t_elem	*new_start;

	temp = *stack;
	if (!temp || !temp->next)
		return ;
	new_start = temp->next;
	temp->next = new_start->next;
	new_start->next = temp;
	*stack = new_start;
	write(1, "swap\n", 5);
}

void	push(t_elem **to_push, t_elem **push_to)
{
	t_elem	*new_to_push;
	t_elem	*new_push_to;

	new_push_to = *to_push;
	new_to_push = new_push_to->next;
	new_push_to->next = *push_to;
	*to_push = new_to_push;
	*push_to = new_push_to;
	write(1, "push\n", 5);
}


void	rrotate(t_elem **stack)
{
	t_elem	*temp;
	t_elem	*new_start;

	new_start = sw_lstlast(*stack);
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	new_start->next = *stack;
	*stack = new_start;
	write(1, "rrotate\n", 8);
}

void	rotate(t_elem **stack)
{
	t_elem	*temp;
	t_elem	*stack_1;

	stack_1 = *stack;
	temp = stack_1->next;
	stack_1->next = NULL;
	sw_lstadd_back(&temp, stack_1);
	*stack = temp;
	write(1, "rotate\n", 7);
}
