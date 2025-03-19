/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:10:56 by stempels          #+#    #+#             */
/*   Updated: 2025/03/19 09:38:00 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	ra(t_list **stack, int act)
{
	if (!stack)
		return ;
	while (act > 0)
	{
		rotate(stack);
		act--;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack, int act)
{
	if (!stack)
		return ;
	while (act > 0)
	{
		rotate(stack);
		act--;
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_1, t_list **stack_2, int act)
{
	if (!stack_1 || !stack_2)
		return ;
	while (act > 0)
	{
		rotate(stack_1);
		rotate(stack_2);
		act--;
		write(1, "rr\n", 3);
	}
}
