/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:53:36 by stempels          #+#    #+#             */
/*   Updated: 2025/03/18 17:31:20 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*new;

	temp = *stack;
	if (!temp || ! temp->next)
		return ;
	new = temp->next;
	temp->next = new->next;
	new->next = temp;
	*stack = new;
}

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
