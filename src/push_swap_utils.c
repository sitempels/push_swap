/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:37 by stempels          #+#    #+#             */
/*   Updated: 2025/01/31 15:52:24 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_elem	*error_handler(char *fault)
{
	write(1, "Error !", 7);
	if (fault)
	{
		free(fault);
		fault = NULL;
	}
	return (NULL);
}

void	init_struct(t_elem *stack, t_ope *act, t_ctrl *ctrl)
{
	if (stack)
	{
		stack->elem = 0;
		stack->next = NULL;
	}
	if (act)
	{
		act->name = NULL;
		act->ope = NULL;
		act->next = NULL;
		act->previous = NULL;
	}
	if (ctrl)
	{
		ctrl->error = 1;
		ctrl->min = INT_MAX;
		ctrl->max = INT_MIN;
		ctrl->stack_a = NULL;
		ctrl->stack_b = NULL;
		ctrl->act = NULL;
	}
}

int	is_sorted(int sens, t_elem *stack)
{
	t_elem	*ptr;
	t_elem	*origin;

	origin = stack;
	ptr = stack->next;
	while (ptr)
	{
		if (sens == '+' && ptr->elem <= stack->elem)
			return (0);
		if (sens == '-' && ptr->elem >= stack->elem)
			return (0);
		ptr = ptr->next;
		stack = stack->next;
	}
	stack = origin;
	return (1);
}
