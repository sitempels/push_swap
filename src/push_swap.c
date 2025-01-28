/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:23 by stempels          #+#    #+#             */
/*   Updated: 2025/01/28 16:09:48 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*???*/	ft_push_swap(t_elem *a_stack, t_elem *b_stack, t_ope *act)
{
	if (!a_stack || !b_stack || !act)
		return (quit());

}

t_elem	**parse_str(char *str, int *min, int *max)
{
	int	i;
	char 	**array;
	t_elem	*new;
	t_elem	**stack;

	i = 0;
	array = ft_split(str, ' ');
	while (array[i])
	{
		new = sw_new(ft_atoi(array[i]));
		if (!new)
			return (error_handler(/**/));
		if ((new->elem == 0 && array[i][0] != '0') 
			|| (new->elem == -1 && array[i][0] != '-'))
			return (error_handler(/**/));
		if (new->elem < min)
			min = new->elem;
		if (new->elem > max)
			max = new->elem;
		sw_lstadd_back(stack, new);
	}
	return (stack);
}

t_elem	**parse_arg(int argc, char **argv, int *min, int *max)
{
	int	i;
	t_elem	*new;
	t_elem	**stack;

	i = 1;
	while (i <= argc)
	{
		new = sw_new(ft_atoi(argv[i]));
		if (!new)
			return (error_handler(/**/));
		if (new->elem < min)
			min = new->elem;
		if (new->elem > max)
			max = new->elem;
		sw_lstadd_back(stack, new);
		i++;
	}
	return (stack);
}
