/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2manip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:38 by stempels          #+#    #+#             */
/*   Updated: 2025/01/28 15:31:45 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_elem *stack_a, t_elem *stack_b)
{
	if (stack_a->next && stack_b->next)
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	else if (stack_a->next && !stack_b->next)
	{
		swap(stack_a);
		return (1);
	}
	else if (!stack_a->next && stack_b->next)
	{
		swap(stack_b);
		return (1);
	}
	else
		return (-1);
}

int	rr(t_elem *stack_a, t_elem *stack_b)
{
	if (stack_a->next && stack_b->next)
	{
		rotate(stack_a);
		rotate(stack_b);
		return (0);
	}
	else if (stack_a->next && !stack_b->next)
	{
		rotate(stack_a);
		return (1);
	}
	else if (!stack_a->next && stack_b->next)
	{
		rotate(stack_b);
		return (1);
	}
	else
		return (-1);
}

int	rrr(t_elem *stack_a, t_elem *stack_b)
{
	if (stack_a->next && stack_b->next)
	{
		rrotate(stack_a);
		rrotate(stack_b);
		return (0);
	}
	else if (stack_a->next && !stack_b->next)
	{
		rrotate(stack_a);
		return (1);
	}
	else if (!stack_a->next && stack_b->next)
	{
		rrotate(stack_b);
		return (1);
	}
	else
		return (-1);
}
