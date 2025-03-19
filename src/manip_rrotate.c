/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:22:40 by stempels          #+#    #+#             */
/*   Updated: 2025/03/19 11:01:46 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **stack)
{
	t_list	*temp;
	t_list	*ptr;

	temp = ft_lstlast(*stack);
	ptr = *stack;
	while ((ptr->next)->next)
		ptr = ptr->next;
	ptr->next = NULL;
	ft_lstadd_front(stack, temp);
}

void	rra(t_list **stack, int act)
{
	if (!stack)
		return ;
	while (act > 0)
	{
		rrotate(stack);
		act--;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack, int act)
{
	if (!stack)
		return ;
	while (act > 0)
	{
		rrotate(stack);
		act--;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_1, t_list **stack_2, int act)
{
	if (!stack_1 || !stack_2)
		return ;
	while (act > 0)
	{
		rrotate(stack_1);
		rrotate(stack_2);
		act--;
		write(1, "rrr\n", 4);
	}
}
