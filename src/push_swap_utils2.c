/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:40:54 by stempels          #+#    #+#             */
/*   Updated: 2025/03/24 16:00:08 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_free(t_list **lst)
{
	t_list	*ptr2;

	if ((*lst) && (*lst)->next)
		ptr2 = (*lst)->next;
	else
		ptr2 = NULL;
	free(*lst);
	while (ptr2)
	{
		(*lst) = ptr2;
		ptr2 = ptr2->next;
		free(*lst);
	}
	*lst = NULL;
	lst = NULL;
	return ;
}

void	arr_free(char **array)
{
	int	j;

	j = 0;
	while (array[j])
	{
		free(array[j]);
		j++;
	}
	free(array);
	array = NULL;
	return ;
}

t_list	*lst_select(t_list **stack, int content)
{
	t_list	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->content == content)
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}

void	free_on_close(t_list **lst, char **array, int error)
{
	if (*lst)
		lst_free(lst);
	if (array)
		arr_free(array);
	if (error == 1)
		write(1, "Error\n", 6);
}

void	calc_cost(t_ctrl *ctrl, int a, int b)
{
	int	c;

	c = INT_MAX;
	if ((a <= 0 && b <= 0) || (a >= 0 && b >= 0))
	{
		if (ft_abs(a) > ft_abs(b))
			c = ft_abs(a);
		if (ft_abs(a) < ft_abs(b))
			c = ft_abs(b);
	}
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
		c = ft_abs(ft_abs(a) + ft_abs(b));
	if (c < ctrl->cost)
	{
		ctrl->cost = c;
		ctrl->cost_a = a;
		ctrl->cost_b = b;
	}
}
