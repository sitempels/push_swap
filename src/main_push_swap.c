/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:30:14 by stempels          #+#    #+#             */
/*   Updated: 2025/03/06 12:08:53 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctrl	ctrl;
	t_elem	*ptr;
	t_elem	*ptr1;

	init_struct(NULL, NULL, &ctrl);
	if (argc < 2)
	{
		error_handler(NULL);
		return (-1);
	}
	else if (argc == 2)
		parse_str(&ctrl, argv[1]);
	else
		parse_arg(&ctrl, argc, argv);
	if (ctrl.error == -1)
		return (write(1, "Error !", 7));
	ptr1 = ctrl.stack_a;
	while (ptr1)
	{
		ft_printf_fd(1, "%d\n", ptr1->elem);
		ptr1 = ptr1->next;
	}
	write(1, "-------------------\n", 21);
	ptr = ft_push_swap(&ctrl, ctrl.stack_a, ctrl.stack_b);
	while (ptr)
	{
		ft_printf_fd(1, "%d\n", ptr->elem);
		ptr = ptr->next;
	}
	write(1, "-------------------\n", 21);
	ptr1 = ctrl.stack_a;
	while (ptr1)
	{
		ft_printf_fd(1, "%d\n", ptr1->elem);
		ptr1 = ptr1->next;
	}
	return (0);
}
