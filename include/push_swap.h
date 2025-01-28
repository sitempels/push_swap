/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:23 by stempels          #+#    #+#             */
/*   Updated: 2025/01/28 15:33:29 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
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
	/*???*/	(*ope)(/*???*/);
	struct s_ope	*next;
	struct s_ope	*previous;
}	t_ope;
/**/
/*---------------------------FUNCTIONS----------------------------------------*/
/**/
/*------------UTILS---------*/
/*???*/	quit(void); 
/**/
#endif
