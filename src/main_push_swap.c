/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:30:14 by stempels          #+#    #+#             */
/*   Updated: 2025/01/31 16:31:29 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctrl	ctrl;
	t_elem	*ptr;

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
	{
		write(1, "Error !", 7);
		return (-1);
	}
	ptr = ctrl.stack_a;
	while (ptr)
	{
		ft_printf_fd(1, "%d\n", ptr->elem);
		ptr = ptr->next;
	}
	return (0);
}
