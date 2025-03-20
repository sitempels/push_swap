/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:23 by stempels          #+#    #+#             */
/*   Updated: 2025/03/20 17:03:06 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
/**/
/*---------------------------MACROS-------------------------------------------*/
/**/
/*---------------------------STRUCTURES---------------------------------------*/
/**/
/*---------------------------FUNCTIONS----------------------------------------*/
/**/
void	push_swap(t_list **stack_a);
/*------------MANIP---------*/
void	pa(t_list **stack_a, t_list **stack_b, int act);
void	pb(t_list **stack_b, t_list **stack_a, int act);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack, int act);
void	rb(t_list **stack, int act);
void	rr(t_list **stack_1, t_list **stack_2, int act);
void	rra(t_list **stack, int act);
void	rrb(t_list **stack, int act);
void	rrr(t_list **stack_1, t_list **stack_2, int act);
/*------------UTILS---------*/
t_list	*lst_select(t_list **stack, int	content);
void	lst_free(t_list **lst);
void	arr_free(char **array);
int		get_lststart(t_list **stack, char sens);
int		check_spike(t_list **stack, char sens);
int		node_pos(t_list **stack, int content);
int		is_sorted(t_list **stack, char sens);
void	move_first(t_list **stack_a, int pos_a, t_list **stack_b, int pos_b);
/**/
#endif
