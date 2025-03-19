/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:18:53 by stempels          #+#    #+#             */
/*   Updated: 2025/03/19 17:37:05 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **stack, int size);
static void	sort_else(t_list **stack_a, t_list **stack_b, int size_a);
static void	get_node(t_ctrl *ctrl, t_list **stack_a, t_list **stack_b);
static void	calc_cost(t_ctrl *ctrl, int a, int b);

void	push_swap(t_list **stack_a)
{
	int		size_sta;
	t_list	*stack_b;

	stack_b = NULL;
	size_sta = ft_lstsize(*stack_a);
	if (size_sta == 0)
		return ;
	if (size_sta < 4)
		sort_3(stack_a, size_sta);
	else
		sort_else(stack_a, &stack_b, size_sta);
	if (check_spike(stack_a, '+') != 1)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	if ((*stack_a)->content != get_lststart(stack_a, '+'))
	{
		size_sta = node_pos(stack_a, get_lststart(stack_a, '+'));
		move_first(stack_a, size_sta, NULL, 0);
	}
	return ;
}

static void	sort_3(t_list **stack, int size)
{
	int	pos;

	while (!is_sorted(stack, '+'))
	{
		if (check_spike(stack, '+') == 1)
		{
			pos = node_pos(stack, get_lststart(stack, '+'));
			move_first(stack, pos, NULL, 0);
			return ;
		}
		if (size > 2)
			sa(stack);
		pos = node_pos(stack, get_lststart(stack, '+'));
		move_first(stack, pos, NULL, 0);
	}
	return ;
}

static void	sort_else(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_ctrl	ctrl;

	if (is_sorted(stack_a, '+'))
		return ;
	pb(stack_b, stack_a, size_a - 3);
	sort_3(stack_a, 3);
	while (*stack_b)
	{
		get_node(&ctrl, stack_a, stack_b);
		move_first(stack_a, ctrl.cost_a, stack_b, ctrl.cost_b);
		if ((*stack_b)->content > get_lststart(stack_a, '-'))
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
		}
		else
			pa(stack_a, stack_b, 1);
	}
}

static void	get_node(t_ctrl *ctrl, t_list **stack_a, t_list **stack_b)
{
	int		cost_a;
	int		cost_b;
	t_list	*ptr_a;
	t_list	*ptr_b;

	ctrl->cost = INT_MAX;
	ptr_b = (*stack_b);
	while (ptr_b)
	{
		cost_b = node_pos(stack_b, ptr_b->content);
//		get right node: least cost, right place
		while (ptr_a)
		{
			cost_a = node_pos(stack_a, ptr_a->content);

		}
	}
}

int	get_node_a(stack_a, int value_b, int cost_b)
{
	int	cost_a;
	t_list	*ptr_a;

	ptr_a = (*stack_a);
	while (ptr_a)
	{
		if (	
	}
}

static void	calc_cost(t_ctrl *ctrl, int a, int b)
{
	int	c;

	if ((a <= 0 && b <= 0) || (a >= 0 && b >= 0))
		c = ft_abs(ft_abs(a) - ft_abs(b));
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
		c = ft_abs(ft_abs(a) + ft_abs(b));
	if (c < ctrl->cost)
	{
		ctrl->cost = c;
		ctrl->cost_a = a;
		ctrl->cost_b = b;
	}
}
