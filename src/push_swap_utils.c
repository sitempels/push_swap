/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:16:45 by stempels          #+#    #+#             */
/*   Updated: 2025/03/20 10:21:44 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lststart(t_list **stack, char sens)
{
	int		lst_start;
	t_list	*ptr;

	ptr = (*stack);
	if (sens == '+')
		lst_start = INT_MAX;
	if (sens == '-')
		lst_start = INT_MIN;
	while (sens == '+' && ptr)
	{
		if (ptr->content < lst_start)
			lst_start = ptr->content;
		ptr = ptr->next;
	}
	while (sens == '-' && ptr)
	{
		if (ptr->content > lst_start)
			lst_start = ptr->content;
		ptr = ptr->next;
	}
	return (lst_start);
}

int	check_spike(t_list **stack, char sens)
{
	int		spike;
	t_list	*ptr;

	ptr = (*stack);
	spike = 0;
	while (sens == '+' && ptr->next)
	{
		if (ptr->content > (ptr->next)->content)
			spike++;
		ptr = ptr->next;
	}
	if (sens == '+' && ptr->content > (*stack)->content)
		spike++;
	while (sens == '-' && ptr->next)
	{
		if (ptr->content < (ptr->next)->content)
			spike++;
		ptr = ptr->next;
	}
	if (sens == '-' && ptr->content < (*stack)->content)
		spike++;
	return (spike);
}

int	node_pos(t_list **stack, int content)
{
	int		pos;
	int		lst_size;
	t_list	*ptr;

	if (!*stack)
		return (0);
	pos = 0;
	ptr = (*stack);
	while (ptr)
	{
		pos++;
		if (ptr->content == content)
			break ;
		ptr = ptr->next;
	}
	lst_size = ft_lstsize(*stack);
	if (pos > ((lst_size / 2) + (lst_size % 2)))
		pos = (lst_size - pos) * (-1);
	return (pos - 1);
}

void	move_first(t_list **stack_a, int pos_a, t_list **stack_b, int pos_b)
{
	while ((pos_a > 0 && pos_b > 0) && (*stack_a && *stack_b))
	{
		rr(stack_a, stack_b, 1);
		pos_a--;
		pos_b--;
	}
	while ((pos_a < 0 && pos_b < 0) && (*stack_a && *stack_b))
	{
		rrr(stack_a, stack_b, 1);
		pos_a++;
		pos_b++;
	}
	if (pos_a > 0 && *stack_a)
		ra(stack_a, pos_a);
	if (pos_a < 0 && *stack_a)
		rra(stack_a, -1 * pos_a);
	if (pos_b > 0 && *stack_b)
		rb(stack_b, pos_b);
	if (pos_b < 0 && *stack_b)
		rrb(stack_b, -1 * pos_b);
}

int	is_sorted(t_list **stack, char sens)
{
	if (check_spike(stack, sens) != 1)
		return (0);
	if ((*stack)->content == get_lststart(stack, sens))
		return (1);
	return (0);
}
