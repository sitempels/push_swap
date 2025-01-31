/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:23 by stempels          #+#    #+#             */
/*   Updated: 2025/01/31 16:29:23 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
/**/
/*---------------------------MACROS-------------------------------------------*/
# define ER_01 "Error: Not enough arguments !\n"
# define ER_02 "Error: Input only integers!\n"
# define ER_03 "Error: Duplicated arguments!\n"
/**/
/*---------------------------STRUCTURES---------------------------------------*/
typedef struct	s_elem
{
	int			elem;
	struct s_elem	*next;
}	t_elem;

typedef struct	s_ope
{
	char	*name;
	int		(*ope)();
	struct s_ope	*next;
	struct s_ope	*previous;
}	t_ope;

typedef struct	s_ctrl
{
	int			error;
	int			min;
	int			max;
	struct s_elem	*stack_a;
	struct s_elem	*stack_b;
	struct s_ope	*act;
}	t_ctrl;
/**/
/*---------------------------FUNCTIONS----------------------------------------*/
int	parse_str(t_ctrl *ctrl, char *str);
int	parse_arg(t_ctrl *ctrl, int argc, char **argv);
/**/
/*------------MANIP---------*/
int	swap(t_elem *stack);
void	push(t_elem *to_push, t_elem *push_to);
int	rotate(t_elem *stack);
int	rrotate(t_elem *stack);
int	ss(t_elem *stack_a, t_elem *stack_b);
int	rr(t_elem *stack_a, t_elem *stack_b);
int	rrr(t_elem *stack_a, t_elem *stack_b);
t_elem	*sw_new(int a);
t_elem	*sw_lstlast(t_elem *lst);
void	sw_lstadd_back(t_elem *stack, t_elem **new);
/*------------UTILS---------*/
void	init_struct(t_elem *stack, t_ope *act, t_ctrl *ctrl);
t_elem	*error_handler(char *fault);
int	is_sorted(int sens, t_elem *stack);
/**/
#endif
