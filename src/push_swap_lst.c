/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:58 by stempels          #+#    #+#             */
/*   Updated: 2025/01/28 15:49:32 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*sw_new(int a)
{
	t_elem	*new;

	new = (t_elem *) malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->elem = a;
	new->next = NULL;
	return (new);
}

void	sw_lstadd_back(t_elem **lst, t_elem *new)
{
	t_elem	*temp;

	temp = sw_lstlast(*lst);
	if (!temp)
		*lst = new;
	else
		temp -> next = new;
}

t_elem	*sw_lstlast(t_elem *lst)
{
	t_elem	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}
