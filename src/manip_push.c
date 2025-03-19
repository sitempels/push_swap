/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:00:09 by stempels          #+#    #+#             */
/*   Updated: 2025/03/18 18:23:53 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

	temp = (*stack_1)->next;
	(*stack_1)->next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = temp;
}

void	pa(t_list **stack_a, t_list **stack_b, int act)
{
	if (!stack_b)
		return ;
	while (act > 0)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
		act--;
	}
}

void	pb(t_list **stack_b, t_list **stack_a, int act)
{
	if (!stack_a)
		return ;
	while (act > 0)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
		act--;
	}
}
