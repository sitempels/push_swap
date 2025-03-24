/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:18:53 by stempels          #+#    #+#             */
/*   Updated: 2025/03/24 15:58:12 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **stack, int size);
static void	sort_else(t_list **stack_a, t_list **stack_b, int size_a);
static void	get_node(t_ctrl *ctrl, t_list **stack_a, t_list **stack_b);
static int	get_node_a(t_list **stack_a, int value_b);

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
		pa(stack_a, stack_b, 1);
	}
}

static void	get_node(t_ctrl *ctrl, t_list **stack_a, t_list **stack_b)
{
	int		cost_a;
	int		cost_b;
	t_list	*ptr_b;

	ctrl->cost = INT_MAX;
	ctrl->cost_a = INT_MAX;
	ctrl->cost_b = INT_MAX;
	ctrl->lst_min = get_lststart(stack_a, '+');
	ctrl->lst_max = get_lststart(stack_a, '-');
	ptr_b = (*stack_b);
	while (ptr_b)
	{
		if (ptr_b->content < ctrl->lst_min)
			cost_a = node_pos(stack_a, get_lststart(stack_a, '+'));
		else if (ptr_b->content > ctrl->lst_max)
			cost_a = node_pos(stack_a, get_lststart(stack_a, '-')) + 1;
		else
			cost_a = get_node_a(stack_a, ptr_b->content);
		cost_b = node_pos(stack_b, ptr_b->content);
		calc_cost(ctrl, cost_a, cost_b);
		ptr_b = ptr_b->next;
	}
}

static int	get_node_a(t_list **stack_a, int value_b)
{
	int		cost_a;
	t_list	*ptr_a;

	cost_a = INT_MAX;
	ptr_a = (*stack_a);
	if ((ft_lstlast(*stack_a))->content < value_b && value_b < ptr_a->content)
		cost_a = node_pos(stack_a, ptr_a->content);
	else
	{
		while (ptr_a->next)
		{
			if (ptr_a->content < value_b && value_b < (ptr_a->next)->content)
			{
				cost_a = node_pos(stack_a, (ptr_a->next)->content);
				break ;
			}
			ptr_a = ptr_a->next;
		}
	}
	return (cost_a);
}
