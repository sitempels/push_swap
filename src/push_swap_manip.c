/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:24 by stempels          #+#    #+#             */
/*   Updated: 2025/01/31 15:39:50 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_elem *stack)
{
	t_elem	*temp;

	if (!stack || !stack->next)
		return (-1);
	temp = stack->next;
	stack->next = temp->next;
	temp->next = stack;
	return (0);
}

void	push(t_elem *to_push, t_elem *push_to)
{
	t_elem	*temp;

	if (!to_push)
		return ;
	temp = to_push;
	to_push = temp->next;
	temp->next = push_to;
	push_to = temp;
}

int	rotate(t_elem *stack)
{
	t_elem	*ptr;
	t_elem	*temp;
	
	if (!stack->next)
		return (-1);
	temp = stack;
	temp->next = NULL;
	ptr = stack->next;
	stack = stack->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
	return (0);
}

int	rrotate(t_elem *stack)
{
	t_elem	*ptr;
	t_elem	*temp;

	if (!stack)
		return (-1);
	ptr = stack->next;
	while (ptr->next)
		ptr = ptr->next;
	temp = ptr;
	ptr = NULL;
	temp->next = stack;
	stack = temp;
	return (0);
}
