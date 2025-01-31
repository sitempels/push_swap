/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:23 by stempels          #+#    #+#             */
/*   Updated: 2025/01/31 16:34:47 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_elem	*ft_push_swap(t_ctrl *ctrl, t_elem *stack_a, t_elem *stack_b)
{
	if (!stack_a)
		return (NULL);
	while (!is_sorted('+', stack_a) || !is_sorted('-', stack_b))
	{
		if (stack_a->elem < ((ctrl->max - ctrl->max) / 2))
			push(stack_a, stack_b);
	}
	return (stack_a);
}

int	parse_str(t_ctrl *ctrl, char *str)
{
	int	i;
	char 	**array;
	t_elem	*new;

	i = 0;
	array = ft_split(str, ' ');
	while (array[i])
	{
		new = sw_new(ft_atoi(array[i]));
		if (!new)
			return (0);
		if (new->elem < INT_MIN || new->elem > INT_MAX) 
			return (0);
		if (new->elem < ctrl->min)
			ctrl->min = new->elem;
		if (new->elem > ctrl->max)
			ctrl->max = new->elem;
		sw_lstadd_back(ctrl->stack_a, &new);
		i++;
	}
	return (1);
}

int	parse_arg(t_ctrl *ctrl, int argc, char **argv)
{
	int	i;
	t_elem	*new;

	i = 1;
	while (i < argc)
	{
		new = sw_new(ft_atoi(argv[i]));
		if (!new)
			return (0);
		if ((new->elem == 0 && argv[i][0] != 0) || (new->elem > 0 && argv[i][0] == '-') || (new->elem < 0 && argv[i][0] != '-'))
			return (0);
		if (new->elem < ctrl->min)
			ctrl->min = new->elem;
		if (new->elem > ctrl->max)
			ctrl->max = new->elem;
		sw_lstadd_back(ctrl->stack_a, &new);
		i++;
	}
	return (1);
}
