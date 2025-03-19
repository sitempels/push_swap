/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:40:54 by stempels          #+#    #+#             */
/*   Updated: 2025/03/19 16:06:08 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_free(t_list **lst)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr2 = (*lst)->next;
	free(*lst);
	while (ptr2)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
		free(ptr1);
	}
	lst = NULL;
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
}

t_list	*lst_select(t_list **stack, int	content)
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
